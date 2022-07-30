import torch
from torch import nn
from generate_data import download_mnist_datasets
import sys
import numpy as np
import os

class MnistNetwork(nn.Module):

    def __init__(self):
        super(MnistNetwork, self).__init__()

        self.dense_layers = nn.Sequential(
            nn.Linear(28*28, 25),
            nn.ReLU(), 
            nn.Linear(25, 10)
        )
        self.softmax = nn.Softmax(dim=1)
    
    def forward(self, input_data):
        logits = self.dense_layers(input_data)
        predictions = self.softmax(logits)
        return predictions 

def train(model, data_loader, loss_fn, optimizer, device, epochs):
    for i in range(epochs):
        print(f"Epoch {i+1}")
        train_one_epoch(model, data_loader, loss_fn, optimizer, device)
        print("--------------------")
    print("Training is complete!")

def train_one_epoch(model, data_loader, loss_fn, optimizer, device):
    for inputs, targets in data_loader:
        inputs = np.reshape(inputs, (BATCH_SIZE, 784))
        inputs, targets = inputs.to(device), targets.to(device)

        # calculate loss
        predictions = model(inputs)
        loss = loss_fn(predictions, targets)

        # backpropogate loss and update weights
        optimizer.zero_grad() 
        loss.backward()
        optimizer.step()
    
    print(f"Loss: {loss.item()}")

def save_as_onnx(model, data):
    model.eval()
    input_names=["image"]
    output_names=["predictions"]
    dummy_input = np.reshape(_.dataset[0][0], (1, 784))
    torch.onnx.export(model, dummy_input, "trained_models\\mnist.onnx", verbose=True, input_names=input_names, output_names=output_names)

def save_as_pth(model):
    model.eval()
    torch.save(model.state_dict(), "trained_models\\mnist.pth")

if __name__ == "__main__":

    if len(sys.argv) < 2:
        print("Using default arugments. Sample usage of custom args:")
        print("\ttrain_model.py batch_size epochs")
        print("\ttrain_model.py 16 10")
        BATCH_SIZE = 16
        DEVICE = "cuda" if torch.cuda.is_available() else "cpu"
        EPOCHS = 10
        LEARNING_RATE = .001
    else:
        BATCH_SIZE = sys.argv[1]
        DEVICE = "cuda" if torch.cuda.is_available() else "cpu"
        EPOCHS = sys.argv[2]
        LEARNING_RATE = .001

    # Get Data
    train_data_loader, _ = download_mnist_datasets(BATCH_SIZE, BATCH_SIZE)

    # Build Model
    feed_forward_net = MnistNetwork().to(device=DEVICE)

    loss_fn = nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(feed_forward_net.parameters(), lr=LEARNING_RATE)

    # Train the Model
    train(feed_forward_net, train_data_loader, loss_fn, optimizer, DEVICE, EPOCHS)
    
    if not os.path.isdir("trained_models"):
        os.mkdir("trained_models")
    
    save_as_onnx(feed_forward_net, _)
    save_as_pth(feed_forward_net)

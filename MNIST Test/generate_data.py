import torch
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor
import os
import numpy as np

def download_mnist_datasets():
    train_data = datasets.MNIST(
        root="downloaded", # Where to store the data 
        download=True,
        train=True, # Intersted in the training data
        transform = ToTensor() # Normalizes the pictures
    )
    validation_data = datasets.MNIST(
        root="downloaded", # Where to store the data 
        download=True,
        train=False, # Intersted in the validation data
        transform = ToTensor() # Normalizes the pictures
    )

    return train_data, validation_data

def _convert_data_set(data_loader, sub_folder, file_name):

    if not os.path.isdir(f"txt_data\\{sub_folder}"):
        os.mkdir(f"txt_data\\{sub_folder}")

    inputs, targets = next(iter(data_loader))
    index = 0
    for input, target in zip(inputs, targets):
        data = np.reshape(np.array(input, np.float32), (784))

        file_path = f"txt_data\\{sub_folder}\\{file_name}_{index}"
        file = open(file_path, "w")
        for x in data.tolist():
            x = round(x, 8)
            file.write(str(x) + "\n")
        file.write(str(int(target)))
        file.close()
        index += 1
        print(f"{file_path} created with expected: {target}")

def convert_mnist_to_csv(train_data, validation_data, train_number, validation_number):

    train_data_loader = DataLoader(train_data, batch_size=train_number)
    validation_data_loader = DataLoader(validation_data, batch_size=validation_number)

    if not os.path.isdir("txt_data"):
        os.mkdir(".\\txt_data")
    
    # Write the Training data to their own file
    _convert_data_set(train_data_loader, "training", "train_data")
    
    # Write the Validation data to their own file
    _convert_data_set(validation_data_loader, "validation", "validation_data")


if __name__ == "__main__":
    """ Example of generating txt data """
    train, validation = download_mnist_datasets()
    convert_mnist_to_csv(train, validation,3 ,3)



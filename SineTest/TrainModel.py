import tensorflow as tf
from tensorflow.keras import layers
import matplotlib.pyplot as plt
import tf2onnx
import onnx
import os

from SineTest.GenerateData import generate_data


class SineModel():

    def __init__(self):
        self.model = tf.keras.Sequential()
        self.model.add(layers.Dense(16, activation='relu', input_shape=(1,)))
        self.model.add(layers.Dense(16, activation='relu'))
        self.model.add(layers.Dense(16, activation='relu'))
        self.model.add(layers.Dense(1))
        self.model.compile(optimizer='rmsprop', loss='mse', metrics=['mae'])
        self.model.summary()

        self.x_train, self.x_validate, self.x_test, self.y_train, self.y_validate, self.y_test = generate_data(1000)
        self.train_history = None

    def train(self, epochs, batch_size):
        self.train_history = self.model.fit(self.x_train,
                                            self.y_train,
                                            epochs=epochs,
                                            batch_size=batch_size,
                                            validation_data=(self.x_validate, self.y_validate))

    def evaluate(self):
        loss = self.model.evaluate(self.x_test, self.y_test)
        predictions = self.model.predict(self.x_test)

        print(f"Evaluation Loss: {loss}")
        plt.title('Comparison of predictions and actual values')
        plt.plot(self.x_test, self.y_test, 'b.', label='Actual')
        plt.plot(self.x_test, predictions, 'r.', label='Predicted')
        plt.legend()
        plt.show()

    def save_as_onnx(self):

        if not os.path.isdir(".\\SineTest\\trained_models"):
            os.mkdir(".\\SineTest\\trained_models")

        input_signature = [tf.TensorSpec([1], tf.float32, name='x')]
        onnx_model, _ = tf2onnx.convert.from_keras(self.model, input_signature)
        onnx.save(onnx_model, ".\\SineTest\\trained_models\\sine.onnx")

    def save_as_tf(self):

        if not os.path.isdir(".\\SineTest\\trained_models"):
            os.mkdir(".\\SineTest\\trained_models")

        self.model.save(".\\SineTest\\trained_models\\sine_model")

    def graph_train_history(self, starting_index):

        if self.train_history is None:
            print("Model hasn't trained yet.")
            return

        loss = self.train_history.history["loss"]
        val_loss = self.train_history.history['val_loss']

        epochs = range(1, len(loss) + 1)

        plt.plot(epochs[starting_index:], loss[starting_index:], 'g.', label='Training loss')
        plt.plot(epochs[starting_index:], val_loss[starting_index:], 'b.', label='Validation loss')
        plt.title('Training and validation loss')
        plt.xlabel('Epochs')
        plt.ylabel('Loss')
        plt.legend()
        plt.show()


def train_a_model(epochs: int, batch_size: int):
    MySineModel = SineModel()

    MySineModel.train(epochs, batch_size)
    MySineModel.graph_train_history(100)
    MySineModel.evaluate()
    MySineModel.save_as_onnx()
    MySineModel.save_as_tf()

from turtle import down
import onnxruntime as ort
import numpy as np
from generate_data import download_mnist_datasets
from load_data_from_txt import load_data_from_txt
import os

def predict(session, a_input, target, class_mapping):
    
    predictions = session.run(None, {"image": [a_input]})
    predicted_index = predictions[0][0].argmax(0)
    predicted=class_mapping[predicted_index]
    expected = class_mapping[target]

    return predicted, predictions, expected

def print_input(input):
    counter=0
    for value in input:
        print(f"{value:.6f}", end=" ")
        counter +=1
        if counter == 28:
            print()
            counter =0

def make_predictions(inputs, actuals, session, class_mapping):
    for index, input in enumerate(inputs):
        target = actuals[index]

        predicted, predictions, expected = predict(session, input, target, class_mapping)
    
        print_input(input)
        print()
        print(f"{predicted=}")
        for prediction in predictions[0][0]:
            print(f"{float(prediction):.6f}", end=" ")
        print()
        print(f"{expected=}")
        print()


if __name__ == "__main__":
    
    class_mapping = [
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"
    ]

    training_inputs, training_actuals = load_data_from_txt("training")
    validation_inputs, validation_actuals = load_data_from_txt("validation")

    ort_session = ort.InferenceSession("trained_models\\mnist.onnx")
    make_predictions(training_inputs, training_actuals, ort_session, class_mapping)
    make_predictions(validation_inputs, validation_actuals, ort_session, class_mapping)

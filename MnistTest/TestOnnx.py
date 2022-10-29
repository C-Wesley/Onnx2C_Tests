import onnxruntime as ort
import csv
import os

from MnistTest.LoadDataFromTxt import load_data_from_txt



def predict(session, a_input, target, class_mapping):
    
    predictions = session.run(None, {"image": [a_input]})
    predicted_index = predictions[0][0].argmax(0)
    predicted=class_mapping[predicted_index]
    expected = class_mapping[target]

    return predicted, predictions, expected

def print_input(input):
    counter=0
    for value in input:
        print(f"{value:.7f}", end=" ")
        counter +=1
        if counter == 28:
            print()
            counter =0

def make_predictions(inputs, actuals, session, class_mapping, data_set, display_input:bool = False):
    if not os.path.isdir("MnistTest\\predictions"):
        os.mkdir("MnistTest\\predictions")
        file = open("MnistTest\\prediciton\\python_inferences.csv", 'w', encoding="UTF8", newline="")
    else:
        file = open("MnistTest\\predictions\\python_inferences.csv", 'a', encoding='UTF8', newline="")
    
    csv_file = csv.writer(file)
    header = ["Expected", "Predicted", "Predictions", data_set]
    csv_file.writerow(header)

    for index, input in enumerate(inputs):
        target = actuals[index]

        predicted, predictions, expected = predict(session, input, target, class_mapping)

        if display_input:
            print_input(input)
        print(f"{expected=}")

        data = [expected, predicted]
        for prediction in predictions[0][0]:
            print(f"{float(prediction):.6f}", end=" ")
            data.append(f"{prediction:.6f}")
        print()
        print(f"{predicted=}")
        print()
        

        
        csv_file.writerow(data)

def run_predictions():
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

    ort_session = ort.InferenceSession("MnistTest\\trained_models\\mnist.onnx")

    # Reset the Inference File
    if os.path.isdir("MnistTest\\predictions"):
        files = os.listdir("MnistTest\\predictions")
        for file in files:
            os.remove(f"MnistTest\\predictions\\{file}")

    make_predictions(training_inputs, training_actuals, ort_session, class_mapping, "training")
    make_predictions(validation_inputs, validation_actuals, ort_session, class_mapping, "validation")

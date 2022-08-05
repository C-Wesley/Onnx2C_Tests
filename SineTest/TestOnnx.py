import onnxruntime as ort
from SineTest.LoadDataFromTxt import load_data_from_txt


def predict(session, a_input):

    prediction = session.run(None, {"x": [a_input]})
    return prediction


def run_predictions():
    ort_session = ort.InferenceSession(".\\SineTest\\trained_models\\sine.onnx")

    x_data, y_data = load_data_from_txt()

    predictions = []

    for x in x_data:
        predictions.append(predict(ort_session, x)[0][0][0])

    for input, output in zip(x_data, predictions):
        print(f"Input: {input}")
        print(f"Output: {output}")
        print("\n")

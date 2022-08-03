import onnxruntime as ort
from load_data_from_txt import load_data_from_txt
import matplotlib.pyplot as plt


def predict(session, a_input):

    prediction = session.run(None, {"x": [a_input]})
    return prediction


if __name__ == "__main__":
    ort_session = ort.InferenceSession("trained_models\\sine.onnx")

    x_data, y_data = load_data_from_txt()

    predictions = []

    for x in x_data:
        predictions.append(predict(ort_session, x)[0][0][0])

    for input, output in zip(x_data, predictions):
        print(f"Input: {input}")
        print(f"Output: {output}")
        print("\n")

    # plt.plot(x_data, y_data, "b.")
    # plt.plot(x_data, predictions, "r.")
    # plt.show()

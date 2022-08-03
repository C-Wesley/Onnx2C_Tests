import os
import numpy as np
import matplotlib.pyplot as plt


def load_data_from_txt():
    os.chdir("txt_data")

    x_file = open("x_values.txt", "r")
    y_file = open("y_values.txt", "r")

    x_data = x_file.readlines()
    y_data = y_file.readlines()

    x_file.close()
    y_file.close()

    os.chdir("..")

    return np.asarray(x_data, np.float32), np.asarray(y_data, np.float32)


if __name__ == "__main__":
    x_data, y_data = load_data_from_txt()

    plt.title("Sample Data")
    plt.plot(x_data, y_data, "b.")
    plt.show()

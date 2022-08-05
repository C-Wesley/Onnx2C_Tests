import os
import numpy as np


def load_data_from_txt():
    original = os.getcwd()
    os.chdir(".\\SineTest\\txt_data")

    x_file = open("x_values.txt", "r")
    y_file = open("y_values.txt", "r")

    x_data = x_file.readlines()
    y_data = y_file.readlines()

    x_file.close()
    y_file.close()

    os.chdir(original)

    return np.asarray(x_data, np.float32), np.asarray(y_data, np.float32)

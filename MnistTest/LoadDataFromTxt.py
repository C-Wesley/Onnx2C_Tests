from argparse import ArgumentError
import os
import numpy as np

def load_data_from_txt(path):
    if path =="training" or path =="validation":
        original_path = os.getcwd()
        os.chdir(f"txt_data\\{path}")
        files = os.listdir()

        inputs = []
        actuals = []

        for f in files:
            file = open(f, "r")

            data = file.readlines()
            expected = data.pop()

            inputs.append(data)
            actuals.append(int(expected))
        
        os.chdir(original_path)
        return np.asarray(inputs, np.float32), actuals
    else:
        raise ArgumentError("load_data_from_txt expects 'training' or 'validation'")
    


import tensorflow as tf
import numpy as np
import math
import os


def generate_data(samples):

    seed = 1337
    np.random.seed(seed)
    tf.random.set_seed(seed)

    x_values = np.random.uniform(low=0, high=2*math.pi, size=samples)

    # Generate a uniformly distributed set of random numbers in the range from
    # 0 to 2π, which covers a complete sine wave oscillation
    x_values = np.random.uniform(
        low=0, high=2*math.pi, size=samples).astype(np.float32)

    # Shuffle the values to guarantee they're not in order
    np.random.shuffle(x_values)

    # Calculate the corresponding sine values
    y_values = np.sin(x_values)

    # Add a small random number to each y value
    y_values += 0.1 * np.random.randn(*y_values.shape)

    # Save the data set as a txt file 
    _convert_data_set_to_txt(x_values, y_values)

    # We'll use 60% of our data for training and 20% for testing. The remaining 20%
    # will be used for validation. Calculate the indices of each section.
    TRAIN_SPLIT = int(0.6 * samples)
    TEST_SPLIT = int(0.2 * samples + TRAIN_SPLIT)

    # Use np.split to chop our data into three parts.
    # The second argument to np.split is an array of indices where the data will be
    # split. We provide two indices, so the data will be divided into three chunks.
    x_train, x_validate, x_test = np.split(x_values, [TRAIN_SPLIT, TEST_SPLIT])
    y_train, y_validate, y_test = np.split(y_values, [TRAIN_SPLIT, TEST_SPLIT])

    # Double check that our splits add up correctly
    assert (x_train.size + x_validate.size + x_test.size) == samples

    return (x_train, x_validate, x_test, y_train, y_validate, y_test)


def _convert_data_set_to_txt(x_values, y_values):

    if not os.path.isdir(".\\txt_data"):
        os.mkdir("txt_data")

    x_file = open("txt_data\\x_values.txt", "w")
    for x in x_values:
        x_file.write(str(x) + "\n")

    y_file = open("txt_data\\y_values.txt", "w")
    for y in y_values:
        y_file.write(str(y) + "\n")


if __name__ == "__main__":
    generate_data(1000)

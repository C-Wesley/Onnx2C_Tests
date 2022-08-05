import os
from colorama import Fore, Style
import subprocess

from MenuUtils import print_choices, get_input
from SineTest.GenerateData import generate_data
from SineTest.TestOnnx import run_predictions


def print_title():

    print(f"{Fore.RED}")
    print(r" ________  ___  ________   _______          ")
    print(r"|\   ____\|\  \|\   ___  \|\  ___ \         ")
    print(r"\ \  \___|\ \  \ \  \\ \  \ \   __/|        ")
    print(r" \ \_____  \ \  \ \  \\ \  \ \  \_|/__      ")
    print(r"  \|____|\  \ \  \ \  \\ \  \ \  \_|\ \     ")
    print(r"    ____\_\  \ \__\ \__\\ \__\ \_______\    ")
    print(r"   |\_________\|__|\|__| \|__|\|_______|    ")
    print(r"   \|_________|                             ")

    print(f"{Fore.GREEN}", end="")
    print(r"_________  _______   ________  _________  ________        ")
    print(r"|\___   ___\\  ___ \ |\   ____\|\___   ___\\   ____\      ")
    print(r"\|___ \  \_\ \   __/|\ \  \___|\|___ \  \_\ \  \___|_     ")
    print(r"     \ \  \ \ \  \_|/_\ \_____  \   \ \  \ \ \_____  \    ")
    print(r"      \ \  \ \ \  \_|\ \|____|\  \   \ \  \ \|____|\  \   ")
    print(r"       \ \__\ \ \_______\____\_\  \   \ \__\  ____\_\  \  ")
    print(r"        \|__|  \|_______|\_________\   \|__| |\_________\ ")
    print(r"                        \|_________|         \|_________| ")

    print(f"{Style.RESET_ALL}")


def call_generate_data(len_of_choices: int):

    message = "How many samples of data would you like?"
    num = get_input(len_of_choices, message)
    generate_data(num)
    print("\n\nData Generated!")


def call_test_onnx(len_of_choices: int):
    run_predictions()
    print("\n\nPredictions Ran!")


def call_test_converted(len_of_choices: int):
    original = os.getcwd()
    os.chdir("SineTest\\c_inference\\")

    cmd1 = "gcc main.c model\\sine.c"

    subprocess.call(cmd1)
    os.system('start "c_inferencese" a.exe')

    os.chdir(original)

    print("\n\nInfrances Ran!")


def call_compare_inferences(len_of_choices: int):
    pass


def call_main_menu(len_of_choices: int):
    pass


def sine_menu():
    os.system("cls")

    print_title()

    choices = {
        1: "Generate Data -> Updates the dir 'sine_Test\\txt_data' with new data.",
        2: "Test Onnx File -> Run inferences using the sine.onnx file and onnxruntime in python.",
        3: "Test Convereted C -> Run inferences using the sine.c file.", 
        4: "Compare Inferences -> Run both inferences.",
        5: "Main Menu -> Go Back to the main menu."
    }
    choice_functions = {
        1: call_generate_data,
        2: call_test_onnx,
        3: call_test_converted,
        4: call_compare_inferences,
        5: call_main_menu
    }

    os.system("cls")
    print_title()
    print_choices(choices)
    message = "Please select a number from the above options: "
    choice_functions[get_input(len(choices), message)](len(choices))

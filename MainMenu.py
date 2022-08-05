from colorama import Fore, Style
import os

# Custom Menu Stuff
from MenuUtils import print_choices, get_input
from SineMenu import sine_menu
from MnistMenu import mnist_menu


def print_title():

    print(f"{Fore.RED}")
    print(r" ________  ________   ________      ___    ___  _______  ________      ")
    print(r"|\   __  \|\   ___  \|\   ___  \   |\  \  /  /|/  ___  \|\   ____\     ")
    print(r"\ \  \|\  \ \  \\ \  \ \  \\ \  \  \ \  \/  / /__/|_/  /\ \  \___|     ")
    print(r" \ \  \\\  \ \  \\ \  \ \  \\ \  \  \ \    / /|__|//  / /\ \  \        ")
    print(r"  \ \  \\\  \ \  \\ \  \ \  \\ \  \  /     \/     /  /_/__\ \  \____   ")
    print(r"   \ \_______\ \__\\ \__\ \__\\ \__\/  /\   \    |\________\ \_______\ ")
    print(r"    \|_______|\|__| \|__|\|__| \|__/__/ /\ __\    \|_______|\|_______| ")
    print(r"                                   |__|/ \|__|                         ")

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


def main_menu():

    choices = {
        1: "MNIST Tests",
        2: "Sine Test"
    }
    choice_functions = {
        1: mnist_menu,
        2: sine_menu
    }

    os.system("cls")
    print_title()
    print_choices(choices)
    message = "Please select a number from the above options: "
    choice_functions[get_input(len(choices), message)]()

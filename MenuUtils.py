from colorama import Fore, Style


def print_choices(choices: dict):
    for key, value in choices.items():
        print(f"{Fore.YELLOW}{key}{Style.RESET_ALL}: {value}")


def valid_int(questionable_input: str, min: int, max: int):

    try:
        value = int(questionable_input)
        if value >= min and value <= max:
            return True
        else:
            print(f"\n{Fore.RED}The value {questionable_input} is invalid.")
            print(f"Please input an int from the options.{Style.RESET_ALL}")
    except ValueError:
        print(f"\n{Fore.RED}The value {questionable_input} is invalid.")
        print(f"Please input an int from the options.{Style.RESET_ALL}")


def get_input(len_of_choices: int, message: str):

    LINE_UP = '\033[1A'
    LINE_CLEAR = '\x1b[2K'
    invalid = True
    while invalid:
        print(f"\n{Fore.CYAN}{message}{Style.RESET_ALL}")
        num = input(LINE_CLEAR)

        if valid_int(num, min=1, max=len_of_choices):
            invalid = False
            return int(num)
        else:
            print(LINE_UP * 6, end=LINE_CLEAR)

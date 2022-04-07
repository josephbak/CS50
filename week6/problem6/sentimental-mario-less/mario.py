def main():
    while True:
        height = input("Height: ")
        if height in [str(i) for i in range(1, 9)]:
            break
        else:
            print("Please enter the height between 1 and 8 inclusive.")

    height = int(height)
    for i in range(height):
        print(" " * (height - 1 - i) + "#" * (i + 1))
        # print("#" * (i + 1))
        # print("\n")


if __name__ == "__main__":
    main()
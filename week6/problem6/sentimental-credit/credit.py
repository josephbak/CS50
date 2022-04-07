def main():
    number = input("Number: ")
    if luhn_algorithm(number):
        length = len(number)
        if length_checker(length):
            if length in [13, 16] and int(number[0]) == 4:  # Visa
                print("VISA\n")
            elif length == 15 and int(number[0]) == 3 and (int(number[1]) in [4, 7]):  # Amex
                print("AMEX\n")
            elif length == 16 and int(number[0]) == 5 and (int(number[1]) in [1, 2, 3, 4, 5]):  # MasterCard
                print("MASTERCARD\n")
            else:
                print("INVALID\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


def length_checker(length):
    # length = len(number)
    if length == 13 or length == 15 or length == 16:
        return True
    else:
        return False


def luhn_algorithm(number):
    sum = 0
    reversed_number = number[::-1]
    # adding every other number from index 0
    for i in range(0, len(reversed_number), 2):
        sum += int(reversed_number[i])
    # adding product's digits of every other number form index 1
    for i in range(1, len(reversed_number), 2):
        # the case when the product becomes 2 digits
        if int(reversed_number[i]) >= 5:
            sum += 1 + (2*int(reversed_number[i])) % 10
            # print(1 + (2*int(reversed_number[i]))%10)
        else:
            sum += 2*int(reversed_number[i])

    if sum % 10 == 0:
        return True
    else:
        return False


if __name__ == '__main__':
    main()
from cs50 import get_string


def main():
    digits = {
        "AMEX": [37, 34],
        "MASTERCARD": [51, 52, 53, 54, 55],
        "VISA": [40, 41, 42, 43, 44, 45, 46, 47, 48, 49]
    }

    lenght = {
        "AMEX": 15,
        "MASTERCARD": 16,
        "VISA": [13, 16]
    }

    card = get_string("Card number:")
    x = checkLuhn(card)
    y = len(card)
    z = int(card[0] + card[1])

    if (x == False):
        print("INVALID\n")
    elif (y == lenght["AMEX"] and z in digits["AMEX"]):
        print("AMEX\n")
    elif (y == lenght["MASTERCARD"] and z in digits["MASTERCARD"]):
        print("MASTERCARD\n")
    elif (y in lenght["VISA"] and z in digits["VISA"]):
        print("VISA\n")
    else:
        print("INVALID\n")


def checkLuhn(cardNo):  # luhn algorithm from https://www.geeksforgeeks.org/luhn-algorithm/

    nDigits = len(cardNo)
    nSum = 0
    isSecond = False

    for i in range(nDigits - 1, -1, -1):
        d = ord(cardNo[i]) - ord('0')

        if (isSecond == True):
            d = d * 2

        nSum += d // 10
        nSum += d % 10

        isSecond = not isSecond

    if (nSum % 10 == 0):
        return True
    else:
        return False


main()

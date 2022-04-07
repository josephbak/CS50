def main():
    text = input("Text: ")
    letter_count = count_letters(text)
    word_count = count_words(text)
    sentence_count = count_sentences(text)

    index = coleman_liau_index(letter_count, word_count, sentence_count)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):
    count = 0
    for char in text:
        uni_char = ord(char)  # unicoded character
        if (uni_char >= 65 and uni_char <= 90) or (uni_char >= 97 and uni_char <= 122):
            count += 1
    return int(count)


def count_words(text):
    return int(len(text.split()))  # split by spaces


def count_sentences(text):
    return int(len(text.replace('!', '.').replace('?', '.').split('.'))) - 1  # replace ! and ? by . and split by .


def coleman_liau_index(letter_count, word_count, sentence_count):
    index = round(0.0588 * (letter_count / word_count * 100) - 0.296 * (sentence_count / word_count * 100) - 15.8)
    return index


if __name__ == '__main__':
    main()

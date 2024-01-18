# TODO
import cs50
def main():
    text = getText()
    colemanValue = colemanLiau(text)
    printResult(colemanValue)


def getText():
    text = cs50.get_string("Text: ")
    return text


def colemanLiau(text):

    setencesWordsLetters = countSetencesWordsLetters(text)

    numberSentences = setencesWordsLetters[0]
    numberWords = setencesWordsLetters[1]
    numberLetters = setencesWordsLetters[2]

    L =(float(numberLetters)/float(numberWords)*100)
    S =(float(numberSentences)/float(numberWords)*100)


    return ((0.0588 * L) - (0.296 * S) - 15.8)



def countSetencesWordsLetters(arrayWords):

    setencesWordsLetters = [0,1,0]

    for word in arrayWords:
        for letter in word:
            if (ord(letter) == 33 or ord(letter) == 46 or ord(letter) == 63):
                setencesWordsLetters[0] +=1

            if (ord(letter) == 32):
                setencesWordsLetters[1] +=1

            if ((ord(letter) > 64 and ord(letter) < 91) or (ord(letter) > 96 and ord(letter) < 123)):
                setencesWordsLetters[2] +=1

    return setencesWordsLetters

def printResult(colemanValue):

    if colemanValue >= 16:
        print("Grade 16+")
    elif colemanValue < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(colemanValue)}")


main()
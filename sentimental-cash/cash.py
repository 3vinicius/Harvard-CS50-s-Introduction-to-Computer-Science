# TODO
import cs50
from decimal import Decimal

def main():
    cash =  cs50.get_float("Change owed: ")

    if cash < 0:
        cash =  cs50.get_float("Change owed: ")

    numberCoins = coinsAlgoritme(cash)
    print(numberCoins)






def coinsAlgoritme(cash):

    coins = [0.25,0.10,0.05,0.01]
    numberCoins = 0
    while not cash <  Decimal('1e-9'):
        for coin in coins:
            while coin < cash:
                cash = Decimal(str(cash)) - Decimal(str(coin))
                numberCoins = numberCoins+1
            if abs(Decimal(str(cash)) - Decimal(str(coin))) < 1e-9 :
                numberCoins = numberCoins+1
                return numberCoins

main()
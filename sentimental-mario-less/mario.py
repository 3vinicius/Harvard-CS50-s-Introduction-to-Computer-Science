# TODO
import cs50

def main():
    height = cs50.get_int("Height: ")
    if height < 1 or height > 8 :
        main()
        return
    elif height == 1:
        print("#")
        return 1
    else:
        for x in range(1,height):
            print(" "*(height-x)+"#"*x)
        print("#"*height)


main()
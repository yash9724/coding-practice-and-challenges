# Median of a set of number

def median(list_of_num):
    list_of_num.sort()
    l = len(list_of_num)
    if l%2 == 0:
        n = l//2
        return (list_of_num[n-1] + list_of_num[n])/2
    else:
        return (list_of_num[l//2])


def main():
    try:
        nums = [eval(x) for x in input().split()]
        print(median(nums))
    except Exception as a:
        print(a)


if __name__ == '__main__':
    main()


    



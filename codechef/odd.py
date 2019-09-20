import pandas as pd
import numpy as np

def isSecNum(df):
    type = df[1].dtype.kind
    # print(type)
    if type in 'iufc':
        return sum(df[1].iloc[::2])
    else:
        return None

def main():
    # df = pd.read_csv('test.csv')
    df1 = pd.DataFrame([[1,2,4],[3,4,1],[2,3,4]])
    print(isSecNum(df1))
    df2 = pd.DataFrame([[1,'a',4],[3,'b',1],[2,'c',4]])
    print(isSecNum(df2))


if __name__ == '__main__':
    main()
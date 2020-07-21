# https://www.codechef.com/OCT18B/status/CCIRCLES,yash9724
# problem : Chef and Circles
# Partially solved

def main():
    from sys import stdin 
    from math import sqrt,pow,fabs
    N,Q = [eval(i) for i in input().split()]
    lines=[]
    for _ in range(N):
        lines.append(stdin.readline())
    
    circle=[]
    for line in lines:
        circle.append(tuple([eval(i) for i in line.split()]))

    dist=[]    

    for i in range(0,N-1):
        x1=circle[i][0]
        y1=circle[i][1]
        r1=circle[i][2]
        for j in range(i+1,N):
            x2=circle[j][0]
            y2=circle[j][1]
            r2=circle[j][2]

            D=sqrt(pow((x1-x2),2) + pow((y1-y2),2))
            d1,d2=0,0
            if(D<=r1 or D<=r2):
                #circles are either coinciding or are within on another
                d1=fabs(r1-r2)-D
                d2=fabs(r1+r2)+D
            elif(D<r1+r2):
                #circles are  intersecting
                d1=0
                d2=fabs(r1+r2)+D
            else:
                #circles are distinct
                d1=D-fabs(r1+r2)
                d2=D+fabs(r1+r2)
            
            minDist = min(d1,d2)
            maxDist = max(d1,d2)   
            dist.append((minDist,maxDist))
            
    
    
    queries=[]
    for _ in range(Q):
        queries.append(stdin.readline())
    
    for line in queries:
        K=eval(line)
        count=0
        for d in dist:
            if K>=d[0] and K<=d[1]:
                count+=1
        print(count) 

if __name__=="__main__":
    main()    

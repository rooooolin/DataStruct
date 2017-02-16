import gc

class sqlist:
    def __init__(self):
        self.data=[]
        self.length=0

def listDelete(L):
    for i in range(L.length):
        for j in range(i+1,L.length):
            if L.data[i]==L.data[j]:
                L.length -= 1
                for k in range(j,L.length):
                    L.data[k]=L.data[k+1]
                j -= 1



def listCreat(L):
        tempList=map(int,raw_input().split())
        m=int(tempList[0])
        for i in range(m):
            L.data.append(tempList[i+1])
        L.length=m



n=input()

for i in range(n):
    L=sqlist()
    listCreat(L)
    listDelete(L)
    for j in range(L.length):
        print L.data[j],
    print '\n'
    gc.collect()

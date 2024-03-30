import collections

# https://leetcode.com/discuss/interview-question/2174113/amazon-oa-sde1
water=[[1,3],[2,3]]
land=[[1,2]]
n = 5

def find(x,g):
    if x!=g[x]: 
        g[x]=find(g[x],g)       
    return g[x]
           
l, w=list(range(n+1)), list(range(n+1))
print('default: ', l)
for i,j in land: 
    # print(i)
    # print(j)
    l[find(i,l)]=l[find(j,l)]  #union lands
print('land: ', l)

for i,j in water:
    # print(i)
    # print(j) 
    w[find(i,w)]=w[find(j,w)]    #union waters
print('water: ', w)

ct=collections.Counter(find(i,l) for i in range(1,n+1))
print(ct)
visit=collections.defaultdict(collections.Counter)
# print(visit)
for prov in range(n+1):      # for each land group check if it has repeated water groups
    # print(i)
    i,j=find(prov,l),find(prov,w)
    print('province ', prov, 'is connected to via land to ', i ,', via water to', j)
    visit[i][j]+=1
    if visit[i][j]>1:
        ct[i]=0

print(visit)
# return max(ct.values())
print (max(ct.values()))
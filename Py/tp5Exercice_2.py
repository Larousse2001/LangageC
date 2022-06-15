#Q1: le dictionnaire sera {'a':2, 'b': 3, 'interval':(1,3)}
def segment (a,b,extr1,extr2):
    return ({'a':a,'b':b,'interval':(min(extr1,extr2),max(extr1,extr2))})

#Q2 "lambda" [parameter_list] ":" expression 
#retourne une liste de couple de valeurs entières; coordonnées (x, y) des points apparent tq y=ax+b 
f=lambda d:[(x,d['a']*x+d['b']) for x in range(d['interval'][0],d['interval'][1]+1)]

#Q3: deux droites sont parallèles si les valeurs absolues de leurs coefficients |a| sont égaux.
def parallel(seg1,seg2):
    return abs(seg1['a'])==abs(seg2['a'])

#Q4:le pourcentage en terme de nombre de points apparents communs entre deux segments.
#La formule est : nombre de points apparents communs divisé par la somme des nombres de points apparents des deux segments. Sinon, elle renvoie 0.
def confondus(seg1,seg2):
    if parallel(seg1,seg2):
        pourcentage= len(set(f(seg1))&set(f(seg2)))*100/(len(set(f(seg1)))+len(set(f(seg2))))
        return round(pourcentage,2)

#Q5: renvoie le point apparent d'intersection entre deux segments s'il existe, sinon renvoie 0.
def InterPointApparent(seg1,seg2):
    res=set(set(f(seg1))&set(f(seg2))
    if res==set():
        return 0
    return res

#Q6: 
#     A. Calculez le déterminant **det = (xA − xB)(yC − yD) − (xC − xD)(yA − yB)**
#     B. Calculez **t1 = ((xC − xB)(yC − yD) − (xC − xD)(yC − yB))/det**
#     C. Calculez **t2 = ((xA − xB)(yC − yB) − (xC − xB)(yA − yB))/det**
#     D. Les deux segments se coupent ssi t1 et t2 appartiennent simultanément à [0, 1].
#exple l1=[(-3, -7), (-2, -4), (-1, -1), (0, 2), (1, 5), (2, 8), (3, 11)]
#[A,B]=[(xA,yA),(xB,yB),,,,,]    xA=l1[i][0] yA=l1[i][1] xB=[i+1][0] yB=l1[i+1][1]
#[C,D]=[(xC,yC),,,,,,,(xD,yD)]    xC=l2[0][0] yC=[0][1]    xD=[-1][0]  yD=[-1][1]

def interPointDisc(seg1,seg2):
    l1=f(seg1)
    l2=f(seg2)
    res=[]
    for i in range(len(l1)-1):
        det = (l1[i][0] - l1[i+1][0])*(l2[0][1] - l2[-1][1]) - (l2[0][0] - l2[-1][0])*(l1[i][1] - l1[i+1][1])
        t1 = ((l2[0][0] - l1[i+1][0])*(l2[0][1] - l2[-1][1]) - (l2[0][0] - l2[-1][0])*(l2[0][1] - l1[i+1][1]))/det
        t2 = ((l1[i][0] - l1[i+1][0])*(l2[0][1] - l1[i+1][1]) - (l2[0][0] - l1[i+1][0])*(l1[i][1] - l1[i+1][1]))/det
        if 0<t1<1 and 0<t2<1:
            res.append((l1[i],l1[i+1]))
            break
    if res!=[]:
        for i in range(len(l2)-1):
            det = (l2[i][0] - l2[i+1][0])*(l1[0][1] - l1[-1][1]) - (l1[0][0] - l1[-1][0])*(l2[i][1] - l2[i+1][1])
            t1 = ((l1[0][0] - l2[i+1][0])*(l1[0][1] - l1[-1][1]) - (l1[0][0] - l1[-1][0])*(l1[0][1] - l2[i+1][1]))/det
            t2 = ((l2[i][0] - l2[i+1][0])*(l1[0][1] - l2[i+1][1]) - (l1[0][0] - l2[i+1][0])*(l2[i][1] - l2[i+1][1]))/det
            if 0<t1<1 and 0<t2<1:
                res.append((l2[i],l2[i+1]))
                break
        return res
    return 0

def etude2Segments(seg1,seg2):
    if parallel(seg1,seg2):
        temp=PourConf(seg1,seg2)
        if temp==0:
            print("Les deux segment sont strictement parallèles")
        else:
            print("Les deux segment sont confondus de {}%",format(temp))
    else :
        temp=InterPointApparent(seg1,seg2)
        if temp!=0:
            print("L'intersection des deux segments est :",temp)
        else:
            temp=interPointDisc(seg1,seg2)
                if temp!=0:
                    print("L'intersection des deux segments se trouve entre les points :",temp)
                else:
                    print("Les deux segments ne se coupent pas et ne sont pas parallèle")

# Programme principale pour tester le code ci-dessus
seg1=Segment(3,2,-3,14)
seg2=Segment(-2,1,-5,14)
seg3=Segment(3,2,0,4)
seg4=Segment(1,2,-3,14)

etude2Segments(seg1,seg3)

etude2Segments(seg1,seg2)

etude2Segments(seg3,seg2)

etude2Segments(seg1,seg4)
def tri_selection(tab):
   for i in range(len(tab)):
      # Trouver le min
       min = i
       for j in range(i+1, len(tab)):
           if tab[min] > tab[j]:
               min = j
                
       tmp = tab[i]
       tab[i] = tab[min]
       tab[min] = tmp
   return tab
# Programme principale pour tester le code ci-dessus
tab = [98, 22, 15, 32, 2, 74, 63, 70]
 
tri_selection(tab)
 
print ("Le tableau trié est:")
for i in range(len(tab)):
    print ("%d" %tab[i])


########################################################


def triSelect(l):
    n=len(l)
    for i in range(n):
        minListe=min(l[i-n:])
        posMinListe=l.index(minListe,i,n)
        l[i],l[posMinListe]=l[posMinListe],l[i]


ll=[]
#Boucle infinie pour remplir la liste
while True:
    d=input("-->")
    if d==' ':
        break
    else:
        ll.append(int(d))
triSelect(ll)
print(ll)
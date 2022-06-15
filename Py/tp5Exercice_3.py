#permet de renvoyer toutes les positions d'une chaine de caractère dans un texte, 
#sinon renvoie "-1".
#find(sub[, start[, end]])
def findAll0(chaine ,texte):
    l=[]
    i=0
    n=len(texte)
    while i<n:
        pos=texte.find(chaine,i)
        if pos==-1:
            break
        l.append(pos)
        i=pos+1
    if l==[]:
        return -1
    return l
    
print (findAll0('a','abcekdkanqnfsfnlansnff'))
print (findAll0('zz','abcekdkanqnfsfnlansnff'))

#Redefinir findAll en ajoutant les paramètres optionnels
def findAll(chaine ,texte,start=0,end=-1):
    l=[]
    i=start
    n=len(texte[:end])
    while i<n:
        pos=texte.find(chaine,i,end)
        if pos==-1:
            break
        l.append(pos)
        i=pos+1
    if l==[]:
        return -1
    return l
print (findAll('a','abcekdkanqnfsfnlansnff'))
print (findAll(chaine='a',texte='abcekdkanqnfsfnlansnff'))
print (findAll(texte='abcekdkanqnfsfnlansnff',chaine='a',))
print (findAll('zz','abcekdkanqnfsfnlansnff'))
print (findAll('a','abcekdkanqnfsfnlansnff',9))
print (findAll('a','abcekdkanqnfsfnlansnff',9,15))

f=findAll
print (f('a','abcekdkanqnfsfnlansnff'))


#3.
def isCorCapPonc(text):
    #vérification de la règle1
    #La première lettre du texte est en majuscule
    if text[0].islower(:
       
         return alase
    
    #vérification de la règle2
    #On ne met pas d'espace avant les symboles de ponctuations ".", ",", "!" et "?"
    ponct2=".,!?"
    for i in ponct2:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if text[j-1]== ' ':
                    return False
    
    #vérification de la règle3
    #On doit mettre une espace après les symboles de ponctuations ".", ",", "!", "?", ":" et ";"
    
    ponct3=".,!?:;"
    for i in ponct3:
        l=findAll(i,text)        n=len(text)

        if l!=-1:
            for j in l:
                if j<n-1 and text[j+1 ]not in ' \n':
                    return False

    #vérification de la règle4
    #La lettre juste après les symboles de ponctuations ".", "!" et "?" doit être en majuscule.

    ponct4=".!?"
    for i in ponct4:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if j<n-1 and text[j+2].islowe()
                    return False


    #règle5
    #On doit mettre une espace avant ":" et ";"

    ponct5=":;"
    for i in ponct5:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if text[j-1]!= " ":
                    return False

    #règle6
    #La lettre juste après les symboles de ponctuations ",", ":" et ";" doit être en minuscule.
    ponct6=",:;"
    for i in ponct6:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if j<n-2 and text[j+2].isupper():
                    return False
                    
    return True
    


ch="Bonjour, lsi1A!"
print(ch)
print("----------------------------------------------")
print(isCorCapPonc(ch))
print("----------------------------------------------")


def locErreur(text):
    d={'A':[],'B':[],'C':[],'D':[],'E':[],'F':[]}
    #vérification de la règle1
    #La première lettre du texte est en majuscule
    if text[0].islower():        
        d['A'].append(0)
    
    #vérification de la règle2
    #On ne met pas d'espace avant les symboles de ponctuations ".", ",", "!" et "?"
    ponct2=".,!?"
    for i in ponct2:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if text[j-1]== ' ':
                     d['B'].append(j-1)
    
    #vérification de la règle3
    #On doit mettre une espace après les symboles de ponctuations ".", ",", "!", "?", ":" et ";"
    
    ponct3=".,!?:;"
    for i in ponct3:
        l=findAll(i,text)
        n=len(text)
        if l!=-1:
            for j in l:
                if j<n-1 and text[j+1] not in ' \n':
                     d['C'].append(j+1)

    #vérification de la règle4
    #La lettre juste après les symboles de ponctuations ".", "!" et "?" doit être en majuscule.

    ponct4=".!?"
    for i in ponct4:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if j<n-2 and text[j+2].islower():
                     d['D'].append(j+2)

    #règle5
    #On doit mettre une espace avant ":" et ";"

    ponct5=":;"
    for i in ponct5:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if text[j-1]!= " ":
                     d['E'].append(j-1)

    #règle6
    #La lettre juste après les symboles de ponctuations ",", ":" et ";" doit être en minuscule.
    ponct6=",:;"
    for i in ponct6:
        l=findAll(i,text)
        if l!=-1:
            for j in l:
                if j<n-2 and text[j+2].isupper():
                     d['F'].append(j+2)
                    
    for r in d:
        if d[r]==[]:
            d[r]="Vérifiée"
        else:
            d[r].sort()
    
    return d


#5 exple d={'A': [0], 'B': [36, 48, 101, 166], 'C': [103, 168, 200], 'D': [104, 169], 'E': [199], 'F': [51]}    
def CorCapPonc(text):
    d=locErreur(text)
    listText=list(text)
    #Correction de la règle1
    #La première lettre du texte est en majuscule
    if d['A']!="Vérifiée"  :  
        listText[0]=listText[0].upper()
        
    
    #vérification de la règle2
    #On ne met pas d'espace avant les symboles de ponctuations ".", ",", "!" et "?"
    if d['B']!="Vérifiée"  : 
        elemSup=0
        for i in d['B']:
            del(listText[i-elemSup])
            elemSup=elemSup+1
    
    #vérification de la règle3
    #On doit mettre une espace après les symboles de ponctuations ".", ",", "!", "?", ":" et ";"
    
 
 
    #vérification de la règle4
    #La lettre juste après les symboles de ponctuations ".", "!" et "?" doit être en majuscule.


    #règle5
    #On doit mettre une espace avant ":" et ";"


    #règle6
    #La lettre juste après les symboles de ponctuations ",", ":" et ";" doit être en minuscule.



ch="nous souhaitons tester ce paragraphe , pourcela , Nous avons commis, plusieurs fauts de ponctuations .voyons alors notre correcteur est il, capable de les corrigées ? bien sûr au niveau de détection:Il détecte, certaines erreurs et d'autres aprés la corrections."
print(ch)
print("----------------------------------------------")
print(isCorCapPonc(ch))
print("----------------------------------------------")erreurs=locErreur(ch)
print(erreurs)
print("----------------------------------------------")ch_Corrigee=CorCapPonc(ch,erreurs)
print(ch_Corrigee)
print("----------------------------------------------")
print(isCorCapPonc(ch_Corrigee))
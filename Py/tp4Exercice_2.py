ch="""Les fonctions nous permettent de regrouper des linges de code dans un mini-programme appelé sous-programme.
Ensuite, chaque fois que nous avons besoin de l’utiliser, nous «appelons» simplement cette fonction ; appeler une fonction signifie l’utiliser dans un autre code.
Généralement, une fonction prend une entrée et produit une sortie. Python offre deux catégories de fonction : les fonctions ordinaires et les fonctions lambda."""
alpha={'k', 'x', 'c', 'é', 'v', 'è', 'a', 'w', 'à', 'p', 'd', 'ù', 'g', 'm', 'b', 'l', 'h', 'o', 'r', 'q', 'u', 'i', 't', 'f', 'ç', 'n', 'î', 'ê', 'y', 's', 'j', 'z', 'ï', 'e'}
ponct={',', '?', '.', ':', ';','!'}
# 1. Ecrivez le scripty python permettant d'afficher les caractères de ponctuation utilisés dans **ch**.

e1=(set(ch.lower())-alpha)&ponct
print(e1)
# 2. Ecrivez le scripty python permettant d'afficher les lettres utilisées dans **ch**. Ne différenciez pas les lettres majuscules des minuscules.

e2=set(ch.lower())&alpha
print(e2)
# 3. Ecrivez le scripty python permettant d'afficher les caractères utilisés dans **ch** qui sont ni de ponctuation ni des lettres .

e3=set(ch.lower())-(alpha|ponct)
print(e3)
# 4. Afficher l'ensemble de mots utilisés dans ch et le nombre d'apparition de chaque mot.

l=ch.split()
print(l)
#supprimer la ponctuation à la fin de chaque mot str.strip([chars])  str.join(iterable)
#print (''.join(ponct)) #!?.:,;
#'?fghj;'.strip(''.join(ponct))
ll=[mot.strip(''.join(ponct)) for mot in l]
print(ll)
for i in range(ll.count('')):
    ll.remove('')
print(ll)
# 4.2 le nombre d'apparition de chaque mot.
ensMots=set(ll)
d=dict()
for m in ensMots:
    d[m]=ll.count(m)
print(d)
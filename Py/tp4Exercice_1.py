#Les collections:
#liste l=[ 1,2] g0 d-1 mutables
#tuples t=(1,2) non mutables
#ensembles e={} pas doublons , mutables
#dictionnaires clé valeurs keys values ,mutables , cles immutables
#d={'k1':v1 , 'k2':v2 }
#d=dict([('k1',v1),('k2',v2)])

Joueur = ('A','B')
Score={'A':0,'B':0}
Tour=input('Qui va commencer ? A/B \t')
while(Tour.upper() not in 'AB'):
    Tour=input('Qui va commencer ? A/B \t')
print(Tour)
while(abs(Score['A']-Score['B'])<2):
    C=0
    while(C<20):
        print("C'est le tour du joueur",Tour.upper())
        x=input('Saisir un entier 1 ou 2 ou 3\t')
        while(x not in '123'):
            x=input('Saisir un entier 1 ou 2 ou 3\t')
        C+=int(x)
        print('Compteur =',C)
        if(Tour.upper()=='A'):
            Tour='B'
        else:
            Tour='A'
    Score[Tour.upper()]+=1
    ProchainTour=Joueur-{Tour.upper()}
    Tour=ProchainTour.pop()
if(Score['A']==max[Score.value()]):
    print('Le gagnant est A')
else:
    print('Le gagnant est B')
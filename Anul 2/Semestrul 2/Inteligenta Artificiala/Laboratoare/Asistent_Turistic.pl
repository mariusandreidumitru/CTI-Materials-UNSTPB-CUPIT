% destinatie(Nume, Tip, CostZilnic, Tara)
destinatie(paris, cultura, 100, franta).
destinatie(roma, cultura, 90, italia).
destinatie(amsterdam, relaxare, 80, olanda).
destinatie(alpi, aventura, 70, elvetia).
destinatie(barcelona, natura, 85, spania).
destinatie(lisabona, relaxare, 75, portugalia).

% activitate(Nume, Destinatie, TipActivitate)
activitate(louvre, paris, muzeu).
activitate(colosseum, roma, istorie).
activitate(ciclism, amsterdam, outdoor).
activitate(schi, alpi, sport).
activitate(plaja, barcelona, relaxare).
activitate(plimbare_cu_barca, lisabona, relaxare).

% transport(Oras1, Oras2, Tip, TimpOre, Cost)
transport(paris, roma, avion, 2, 150).
transport(roma, amsterdam, tren, 6, 100).
transport(amsterdam, alpi, masina, 4, 50).
transport(alpi, barcelona, avion, 2, 120).
transport(barcelona, lisabona, tren, 5, 90).

recomanda_destinatie(Preferinta, DurataZile, Buget, Destinatie) :-
    destinatie(Destinatie, Preferinta, CostZilnic, _),
    TotalCost is CostZilnic * DurataZile,
    TotalCost =< Buget.

recomanda_activitati(Destinatie) :-
    write('Activitati disponibile in '), write(Destinatie), write(':'), nl,
    activitate(Nume, Destinatie, Tip),
    write('- '), write(Nume), write(' ('), write(Tip), write(')'), nl,
    fail.
recomanda_activitati(_).

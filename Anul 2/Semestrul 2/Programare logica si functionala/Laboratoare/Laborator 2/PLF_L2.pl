%APLICATIA2
% FAPTE: Cine vinde ce
vinde(alex, trandafiri).
vinde(alex, lalele).
vinde(alex, crizanteme).

vinde(ana, lalele).
vinde(ana, crini).

vinde(andu, lalele).
vinde(andu, nuci).

% Ce este floare
floare(trandafiri).
floare(lalele).
floare(crizanteme).
floare(crini).

% Cine vinde la fel ca Alex un anumit produs
vinde_ca_alex_explicit(Persoana, Produs) :-
    vinde(alex, Produs),
    vinde(Persoana, Produs),
    Persoana \= alex.


afiseaza_vanzatori_ca_alex.  % opreste dupa ultimul rezultat


%PRELUCRARI ARITMETICE

%APLICATIA 1
media_aritmetica(A, B, M_aritmetica):- M_aritmetica=(A+B)/2.
media_armonica(A, B, M):-
            A=\=0,
            B=\=0,
            M is 2/(1/A+1/B).

%APLICATIA 2
maxim(A,B,A):- A>=B.
maxim(A,B,B):- A<B.
minim(A,B,B):- A>=B.
minim(A,B,A):- A<B.

%APLICATIA 3
maxim(A,B,A):- A>=B.
maxim(A,B,B):- A<B.
minim(A,B,B):- A>=B.
minim(A,B,A):- A<B.
maxim3(A,B,C, Max3):- maxim(A,B, R), maxim(R,C, Max3).
minim3(A,B,C, Min3):- minim(A,B, R), minim(R,C, Min3).

%APLICATIA 4
maxim(A, B, A):- A>=B, !.
maxim(A, B, B).
minim(A, B, B):- A>=B, !.
minim(A, B, A).

%APLICATIA 5

f(X, Y, R) :-
    X > -1,
    Y < 1,
    R is X + Y - 2.

f(X, Y, R) :-
    (X =< -1 ; Y >= 1),
    R is X - Y.

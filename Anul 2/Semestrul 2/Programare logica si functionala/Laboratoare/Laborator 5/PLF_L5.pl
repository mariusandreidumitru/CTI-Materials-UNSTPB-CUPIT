%Aplicatia 1
member(X, [X|T]):-!. /*member(X, [X|_]):-!. */
member(X, [H|T]):- member(X,T). /*member(X, [_|T]):- member(X,T). */

%Aplicatia 2
lungime([], 0).
lungime([H|T], L):-lungime(T, L1), L=L1+1.

%Aplicatia 3
suma([], 0).
suma([H|T], S):-suma(T, S1), S=S1+H.

%Aplicatia 4
concatenare([], L2, L2).
concatenare([H1|T1], L2, [H1|TR]):-concatenare(T1, L2, TR).
concatenare3(L1, L2, L3, R):-
            concatenare(L1,L2,R1),
            concatenare(R1,L3,R).

%Aplicatia 5

count(X, [], 0).
count(X, [X|T], R):- count(X, T, R1), R=R1+1, !.
count(X, [H|T], R):- count(X, T, R).

%Aplicatia 6.1
sterge1(X, [X|T], T):-!.
sterge1(X, [Y|T], [Y|T1]):- sterge1(X, T, T1).

%Aplicatia 6.2

sterge2(X, [], []).
sterge2(X, [X|T], R):- sterge2(X,T,R), !.
sterge2(X, [Y|T], [Y|TR]):- sterge2(X, T, TR).

%Aplicatia 7

impartire([], [], []).
impartire([H|T], [H|TPoz], LNeg):- H>=0, impartire(T, TPoz, LNeg), !.
impartire([H|T], LPoz, [H|TNeg]):-impartire(T, LPoz, TNeg). 

%Impartirea unei liste


impart_lista([], _, [], []).
impart_lista([H|T], K, [H|LMici], LMariEgale) :-
    H < K,
    impart_lista(T, K, LMici, LMariEgale).
impart_lista([H|T], K, LMici, [H|LMariEgale]) :-
    H >= K,
    impart_lista(T, K, LMici, LMariEgale).

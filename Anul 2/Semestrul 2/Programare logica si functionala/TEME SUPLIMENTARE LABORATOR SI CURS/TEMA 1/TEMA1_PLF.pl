minim3(A, B, C, Min) :-
    Min1 is min(A, B),
    Min is min(Min1, C).

%Aplicatia 2
e1(X, Y, Rezultat) :-
    X > 2, Y > 1, !,
    Rezultat is X + Y - 1.

e1(X, Y, Rezultat) :-
    Rezultat is X - Y + 1.

e2(X, Y, Z, T, Rezultat) :-
    X > 2, Y > 2, Z > 1, T > 1, !,
    Rezultat is X + Y + Z + T.

e2(X, Y, Z, T, Rezultat) :-
    X > 2, Y > 2, Z < -1, T < -1, !,
    Rezultat is X + Y - Z - T.

e2(X, Y, _, T, Rezultat) :-
    Rezultat is X - Y + T.

%Aplicatia 3
e3(X, Y, Rezultat) :-
    Max is max(X, Y),
    Min is min(X, Y),
    e1(X, Y, E1),
    Rezultat is Max - Min + E1.

e4(X, Y, Z, T, Rezultat) :-
    MaxXYZ is max(X, max(Y, Z)),
    MinYZT is min(Y, min(Z, T)),
    MediaXY is (X + Y) / 2,
    e2(X, Y, Z, T, E2),
    Rezultat is MaxXYZ - MinYZT + MediaXY - E2.


%Aplicatia 6

f(X, Y, F):- X>-1, Y<1, F=X+Y-2, !.
f(X, Y, F):- F=X-Y.
g(X, Y, R):- R= X*X-Y*Y.
expresie(X, Y, R):- f(X,Y,R1), g(X,Y,R2), R=R1+3*R2.

%Aplicatia 7
cmmdc(X, Y, Y):- X mod Y =0, !.
cmmdc(X, Y, D):- R= X mod Y, cmmdc(Y, R, D).
cmmmc(X, Y, M):- cmmdc(X, Y, D), M=(X*Y)/D.

%Aplicatia 8
cmmdc(X, Y, Y):- X mod Y =0, !.
cmmdc(X, Y, D):- R= X mod Y, cmmdc(Y, R, D).
cmmmc(X, Y, M):- cmmdc(X, Y, D), M=(X*Y)/D.
expresie(A, B, C, Rez):- cmmdc(A,C,R1), cmmmc(A,B, R2),
cmmdc(B,C, R3), Rez=R1-R2+R3.


%APLICATIA 9
e(A, B, C, E) :-
    M1 is max(A, C),
    M2 is max(A, B),
    M3 is max(B, C),
    E is max(M1, max(M2, M3)).

%APLICATIA 10
cmmdc(X, Y, Y):- X mod Y =0, !.
cmmdc(X, Y, D):- R= X mod Y, cmmdc(Y, R, D).
cmmmc(X, Y, M):- cmmdc(X, Y, D), M=(X*Y)/D.
cmmdc3(X,Y,Z,D3):- cmmdc(X,Y,R), cmmdc(R,Z,D3).
cmmmc3(X,Y,Z,M3):- cmmmc(X,Y,R), cmmmc(R,Z,M3).

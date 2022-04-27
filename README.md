# Emulator maszyny Turinga
 Obliczający różnicę właściwą: m-n dla m >= n, 0 dla m < n <br />
<br />
                        Postać MT<br />
 M=({q0, q1, q2, q3, q4, q5, q6}, {0,1}, {0,1,B}, δ, q0, B, 0)<br />
<br />
 Tablica przejść (δ):<br />
![image](https://user-images.githubusercontent.com/46067911/165527063-3cfa90f9-3705-4696-bfe2-d2a56e895563.png)


2.	Instrukcja obsługi programu
a)	Uruchamiamy program. Zostaje wyświetlony opis MT.
b)	Podajemy kolejno m i n (liczby całkowite).
c)	Program generuje i wyświetla taśmę wejściową zakodowaną unarnie, ciąg opisów chwilowych dla tej taśmy, wynik(różnicę właściwą m-n) oraz interpretację otrzymanego wyniku.

3.	Przykłady ciągu opisów chwilowych dla parametrów:
m = 2, n = 1
[q0]0010 |- B[q1]010 |- B0[q1]10 |- B01[q2]0 |- B0[q3]11 |- B[q3]011 |- [q3]B011 |- B[q0]011 |- BB[q1]11 |- BB1[q2]1 |- BB11[q2] |- BB1[q4]1 |- BB[q4]1 |- B[q4] |- B0[q6]

# Emulator maszyny Turinga
 Obliczający różnicę właściwą: m-n dla m >= n, 0 dla m < n <br />
<br />
                        Postać MT<br />
 M=({q0, q1, q2, q3, q4, q5, q6}, {0,1}, {0,1,B}, δ, q0, B, 0)<br />
<br />
 Tablica przejść (δ):<br />
 ---------------------------------------<br />
 | δ  |     0    |     1    |     B    |<br />
 ---------------------------------------<br />
 | q0 | (q1,B,P) | (q5,B,P) |     -    |<br />
 | q1 | (q1,0,P) | (q2,1,P) |     -    |<br />
 | q2 | (q3,1,L) | (q2,1,P) | (q4,B,L) |<br />
 | q3 | (q3,0,L) | (q3,1,L) | (q0,B,P) |<br />
 | q4 | (q4,0,L) | (q4,B,L) | (q6,0,P) |<br />
 | q5 | (q5,B,P) | (q5,B,P) | (q6,B,P) |<br />
 | q5 |     -    |     -    |     -    |<br />
 ---------------------------------------<br />

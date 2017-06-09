# QUESTIONS

* [ 0000 ] eine verlustfreie kompression
* [ 0001 ] (ok auf einen baum in ascii art habe ich jetzt nicht so lust) A:1 B:01 C:00
* [ 0010 ] dieser baum geht in beide richtung und hat auch auf der linken seite eine tiefe > 1
* [ 0011 ] 'abaac' braucht als char_array 5byte. Als Huffman {baum aus [001]} wäre der bedarf 7bit + die grösse des baums.
* [ 0100 ] baum aus [001] und die codierten daten : 0011101(endianess?):

foreach bit in codierte_bits
->if bit == 0
--> gehe nach rechts tiefer in den bauem

-> if bit ==1
--> gehe nach links tiefer in den baum

-> wenn aktueller knoten keine childs hat adde den key zum encoded_array hinzu



* [ 0101 ] Nein das kommt drauf an wie der alogrythmus arbeitet in meinem fall habe ich die variante verwendet die immer nur nach rechts den baum ausbaut

* [ 0110 ] Das Codewort ist die codierte bitfolge des wegen für die zeichen in dem codebuch. Das codebuch enthält den baum der zum codieren/decodieren notwendig ist

* [ 0111 ] Der Huffman müsste für jede farbkomponente einzeln durclaufen und auch einen eigenen baum/codewort erstellen (wenn man nicht die farben mit zb 16 shiftet um einen kombinierten wert zu erhalten). Diese 3 codierungen+baum müssten dann auch passend gespeichert werden zb  in einer datei, dafür müssten dann auch weitere dateiheader angelegt werden.

* [ 1000 ] Das in dem histogramm kann man die häufigkeit der farben sehen, da es zum grössten teil nur eine farbe (schwarz) beinhaltet kann so die komprimierung sehr effizient sein
* [ 1001 ] Für anwender die keine verluste haben möchten zb im audiobereich flac, bei fotos raw

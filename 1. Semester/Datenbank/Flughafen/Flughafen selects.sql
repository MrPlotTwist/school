SELECT * from person WHERE vorname = 'Alexander' and (Nachname like 'M%' or Nachname like 'N%');
select vorname || ' ' || nachname as "Name" from person;
SELECT * FROM Gehaltsstufe WHERE monatsgehalt BETWEEN 2000 and 3000;
select * from gehaltsstufe where monatsgehalt >= 2000 and monatsgehalt <= 3000;
SELECT distinct vorname FROM person; 
SELECT gehaltsstufeID, monatsgehalt * 14 as "Jahresgehalt" FROM gehaltsstufe;
SELECT COUNT(*) FROM abteilung;
Geben Sie jene Flugzeuge der Flugzeugtyptabelle aus, deren Sitzplatzanzahl zwischen 100
und 160 Sitzplätzen liegt und die über 10.000 km weit fliegen können. (Punkte 4) 
SELECT * FROM flugzeugtyp WHERE sitzplaetze BETWEEN 100 and 160 and flugstrecke_maximal >= 10000;
Geben Sie jene Reisepassnummern aus, die mit 2 beginnen, auf 0 enden und wo mindestens
2x die Zahl 5 vorkommt.
SELECT reisepassnr FROM reisepass WHERE reisepassnr like '2%5%5%0';
. Geben Sie alle Postleitzahlen und Ortsnamen aus. Ordnen Sie die Ausgabe nach Ortsnamen
und Postleitzahl.
SELECT plz, bezeichnung FROM ort ORDER BY plz, bezeichnzung;

Geben Sie jene Personen aus, die Maier oder Mayer heißen. (überlegen Sie sich wie Sie das
in einem Statement ohne OR Operator abbilden können)

SELECT * FROM person WHERE nachname IN ('Maier','Mayer');

Geben Sie für alle Datensätze aus der Tabelle Land das Kennzeichen und die Bezeichnung
aus, die weder Österreich (Austria) noch Deutschland sind. (2 Lösungsmöglichkeiten) (Punkte
4) 

SELECT kennzeichen, bezeichnung FROM Land WHERE kennzeichen NOT IN ('AUT','GER'); 

3. Geben Sie alle Datensätze der Tabelle Gepaeck aus, in denen das Gepäck 20 kg
überschreitet. Geben Sie zusätzlich ein Feld ?Aufpreis aus, in dem für jedes Kilogramm
Übergewicht ¤ 2,50 verrechnet wird. (Punkte 6) 

SELECT gepaeck.*, (gewicht - 20) * 2.5 as "Aufpreis" FROM Gepaeck WHERE gewicht > 20;

-- Geben Sie eine Liste aller unterschiedlichen Nachnamen die mehrfach vorkommen, aus und die Häufigkeit ihres Vorkommens.
-- Ordnen Sie die Ausgabe nach der Häufigkeit ihres Vorkommens in absteigender Reihenfolge und Nachnamen in aufsteigender Reihenfolge.

SELECT nachname, COUNT(*) AS Anzahl FROM person GROUP BY nachname HAVING COUNT(nachname) > 1 ORDER BY Anzahl DESC, nachname ASC;

-- Geben Sie eine Liste aller Personen aus, die vor 1980 geboren wurden und
-- sortieren Sie die Personen nach Nachname und innerhalb des Nachnamens nach Vorname
SELECT vorname, nachname, geburtsdatum FROM person WHERE geburtsdatum < to_date('01.01.1980','dd.mm.yyyy');
ORDER BY nachname, vorname desc; 

Geben Sie alle Personen der Tabelle Person aus, die zwischen 28.2 und 6.3 Geburtstag haben.
SELECT * FROM person where to_char(geburtsdatum, 'mm.dd.') between '02.28.' and '03.06.';

-- Geben Sie das durchschnittliche Alter aller Personen aus.
select avg(trunc(months_between(sysdate,geburtsdatum)/12)) as Durchschnittsalter -- Oracle
from person;

select vorname, nachname, trunc(months_between(sysdate, geburtsdatum)/12) "Alter"
from person
where trunc(months_between(to_date('01.01.2021', 'dd.mm.yyyy'), geburtsdatum)/12) >= 65
order by 3 desc;

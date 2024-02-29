function addieren() {
    var n1 = parseFloat(document.getElementById("input1").value);
    var n2 = parseFloat(document.getElementById("input2").value);
    var ergebnis = n1 + n2;
    document.getElementById("ergebnis").innerHTML = ergebnis;

    var method = `${n1} + ${n2} = ${ergebnis}`; // erstellt eine Variable, welche die Rechnung in einem String speichert
    addHistory(method);
}

function subtrahieren() {
    var n1 = parseFloat(document.getElementById("input1").value);
    var n2 = parseFloat(document.getElementById("input2").value);
    var ergebnis = n1 - n2;
    document.getElementById("ergebnis").innerHTML = ergebnis;

    var method = `${n1} - ${n2} = ${ergebnis}`;
    addHistory(method);
}

function multiplizieren() {
    var n1 = parseFloat(document.getElementById("input1").value);
    var n2 = parseFloat(document.getElementById("input2").value);
    var ergebnis = n1 * n2;
    document.getElementById("ergebnis").innerHTML = ergebnis;

    var method = `${n1} * ${n2} = ${ergebnis}`;
    addHistory(method);
}

function dividieren() {
    var n1 = parseFloat(document.getElementById("input1").value);
    var n2 = parseFloat(document.getElementById("input2").value);
    var ergebnis = n1 / n2;
    document.getElementById("ergebnis").innerHTML = ergebnis;

    var method = `${n1} / ${n2} = ${ergebnis}`;
    addHistory(method);
}

function addHistory(method) {
    var element = document.getElementById("history"); // holt sich das Element mit der ID "history"
    var item = document.createElement("div"); // erstellt divs für die Rechnungen, welche dann in der History angezeigt werden
    item.textContent = method; // fügt die Rechnung in das div ein
    element.appendChild(item); 
}

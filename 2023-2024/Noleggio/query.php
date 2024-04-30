<?php
// Connessione al database
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "Noleggio";

// Crea la connessione
$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica la connessione
if ($conn->connect_error) {
    die("Connessione fallita: " . $conn->connect_error);
}

// Parametri GET
$codice_cliente = $_GET['codice_cliente'];
$data_noleggio = $_GET['data_noleggio'];

// Query SQL
$sql = "SELECT 
            Noleggi.id_cliente,
            Noleggi.id_auto,
            Noleggi.data_inizio_noleggio,
            Noleggi.km_effettuati,
            Auto.costo_per_km,
            Noleggi.km_effettuati * Auto.costo_per_km AS costo_noleggio
        FROM 
            Noleggi
        INNER JOIN 
            Auto ON Noleggi.id_auto = Auto.id_auto
        WHERE 
            Noleggi.id_cliente = '$codice_cliente'
            AND Noleggi.data_inizio_noleggio = '$data_noleggio'";

// Esegui la query
$result = $conn->query($sql);

// Stampare i risultati in forma tabellare
if ($result->num_rows > 0) {
    echo "<table><tr><th>ID Cliente</th><th>ID Auto</th><th>Data Inizio Noleggio</th><th>Km Effettuati</th><th>Costo per Km</th><th>Costo Noleggio</th></tr>";
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>" . $row["id_cliente"]. "</td><td>" . $row["id_auto"]. "</td><td>" . $row["data_inizio_noleggio"]. "</td><td>" . $row["km_effettuati"]. "</td><td>" . $row["costo_per_km"]. "</td><td>" . $row["costo_noleggio"]. "</td></tr>";
    }
    echo "</table>";
} else {
    echo "0 risultati";
}

// Chiudi la connessione al database
$conn->close();
?>

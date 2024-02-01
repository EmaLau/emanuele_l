<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <title></title>
</head>
<body>

<?php
$servername = "127.0.0.1";
$username = "root";
$password = "";
$database = "Albergo";
$port = 3306;

$conn = mysqli_connect($servername, $username, $password, $database, $port);


if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

echo "Connection Successfully";
$sql = "SELECT * FROM cliente";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        echo "<br>" . "id:" . $row["id_cliente"] . " Cliente: " . $row["nome"] . " " . $row["cognome"] . " " . $row["numero_di_telefono"] . " " . $row["email"] . " " . $row["data_di_nascita"];
    }
} else {
    echo "0 results";
}

?>

</body>
</html>
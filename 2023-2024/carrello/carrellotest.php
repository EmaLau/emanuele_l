<?php
require_once("carrello.php");

$acquisti = new Carrello;

echo "<HR>Aggiungo alcuni prodotti <br>";
$acquisti->aggiungi_carrello("tempera", 5);
$acquisti->aggiungi_carrello("pennello", 15);
$acquisti->aggiungi_carrello("tempera", 3);
$acquisti->aggiungi_carrello("fogliA4", 999);
$acquisti->stampa();
echo "<HR>Cancello prodotto fogliA4<br>";
$acquisti->togli_carrello("fogliA4");
$acquisti->stampa();
echo "<HR>Modifico prodotto pannello<br>";
$acquisti->aggiorna("pennello", 132);
$acquisti->stampa();
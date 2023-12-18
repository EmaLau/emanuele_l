-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Creato il: Dic 18, 2023 alle 22:01
-- Versione del server: 10.4.28-MariaDB
-- Versione PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ristorante`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `camerieri`
--

CREATE TABLE `camerieri` (
  `id_cameriere` int(11) NOT NULL,
  `nome` varchar(30) DEFAULT NULL,
  `cognome` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dump dei dati per la tabella `camerieri`
--

INSERT INTO `camerieri` (`id_cameriere`, `nome`, `cognome`) VALUES
(1, 'santo', 'patrono'),
(2, 'pippo', 'De Santis');

-- --------------------------------------------------------

--
-- Struttura della tabella `ordini`
--

CREATE TABLE `ordini` (
  `id_ordini` int(11) NOT NULL,
  `numero_persone` int(11) DEFAULT NULL,
  `comanda` varchar(500) DEFAULT NULL,
  `id_cameriere` int(11) NOT NULL,
  `id_tavolo` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dump dei dati per la tabella `ordini`
--

INSERT INTO `ordini` (`id_ordini`, `numero_persone`, `comanda`, `id_cameriere`, `id_tavolo`) VALUES
(15, 2, 'Pastina in brodo', 1, 1);

-- --------------------------------------------------------

--
-- Struttura della tabella `tavoli`
--

CREATE TABLE `tavoli` (
  `id_tavolo` int(11) NOT NULL,
  `numeri_posti_max` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dump dei dati per la tabella `tavoli`
--

INSERT INTO `tavoli` (`id_tavolo`, `numeri_posti_max`) VALUES
(1, 2),
(2, 4);

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `camerieri`
--
ALTER TABLE `camerieri`
  ADD PRIMARY KEY (`id_cameriere`);

--
-- Indici per le tabelle `ordini`
--
ALTER TABLE `ordini`
  ADD PRIMARY KEY (`id_ordini`),
  ADD KEY `id_cameriere` (`id_cameriere`),
  ADD KEY `ordini_id_tavoli_index` (`id_tavolo`);

--
-- Indici per le tabelle `tavoli`
--
ALTER TABLE `tavoli`
  ADD PRIMARY KEY (`id_tavolo`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `ordini`
--
ALTER TABLE `ordini`
  MODIFY `id_ordini` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `ordini`
--
ALTER TABLE `ordini`
  ADD CONSTRAINT `ordini_ibfk_1` FOREIGN KEY (`id_cameriere`) REFERENCES `camerieri` (`id_cameriere`),
  ADD CONSTRAINT `ordini_ibfk_2` FOREIGN KEY (`id_tavolo`) REFERENCES `tavoli` (`id_tavolo`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

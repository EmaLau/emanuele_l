-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Creato il: Dic 18, 2023 alle 22:02
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
-- Database: `Albergo`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `cliente`
--

CREATE TABLE `cliente` (
  `id_cliente` int(11) NOT NULL,
  `nome` varchar(50) NOT NULL,
  `cognome` varchar(50) NOT NULL,
  `numero_di_telefono` int(11) NOT NULL,
  `email` varchar(50) NOT NULL,
  `data_di_nascita` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dump dei dati per la tabella `cliente`
--

INSERT INTO `cliente` (`id_cliente`, `nome`, `cognome`, `numero_di_telefono`, `email`, `data_di_nascita`) VALUES
(1, 'Bh', 'SA', 202030, 'a@s.com', 102013);

-- --------------------------------------------------------

--
-- Struttura della tabella `dati_occupanti`
--

CREATE TABLE `dati_occupanti` (
  `id_occupante` int(11) NOT NULL,
  `nome` varchar(50) NOT NULL,
  `cognome` varchar(50) NOT NULL,
  `documento_identità` varchar(20) NOT NULL,
  `id_prenotazione` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `dati_occupanti`
--

INSERT INTO `dati_occupanti` (`id_occupante`, `nome`, `cognome`, `documento_identità`, `id_prenotazione`) VALUES
(1, 'dada', 'daa', 'CA1124DT', 2);

-- --------------------------------------------------------

--
-- Struttura della tabella `prenotazione`
--

CREATE TABLE `prenotazione` (
  `id_prenotazione` int(11) NOT NULL,
  `periodo` int(11) NOT NULL,
  `tipo_trattamento` varchar(50) NOT NULL,
  `numero_occupanti` int(11) NOT NULL,
  `stato_prenotazione` varchar(15) NOT NULL,
  `id_prenotante` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `prenotazione`
--

INSERT INTO `prenotazione` (`id_prenotazione`, `periodo`, `tipo_trattamento`, `numero_occupanti`, `stato_prenotazione`, `id_prenotante`) VALUES
(2, 5, 'FB', 2, 'NON CONFERMATO', 1);

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`id_cliente`);

--
-- Indici per le tabelle `dati_occupanti`
--
ALTER TABLE `dati_occupanti`
  ADD PRIMARY KEY (`id_occupante`),
  ADD KEY `id_prenotazione` (`id_prenotazione`);

--
-- Indici per le tabelle `prenotazione`
--
ALTER TABLE `prenotazione`
  ADD PRIMARY KEY (`id_prenotazione`),
  ADD KEY `id_prenotante` (`id_prenotante`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `cliente`
--
ALTER TABLE `cliente`
  MODIFY `id_cliente` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT per la tabella `dati_occupanti`
--
ALTER TABLE `dati_occupanti`
  MODIFY `id_occupante` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT per la tabella `prenotazione`
--
ALTER TABLE `prenotazione`
  MODIFY `id_prenotazione` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `dati_occupanti`
--
ALTER TABLE `dati_occupanti`
  ADD CONSTRAINT `id_prenotazione` FOREIGN KEY (`id_prenotazione`) REFERENCES `prenotazione` (`id_prenotazione`);

--
-- Limiti per la tabella `prenotazione`
--
ALTER TABLE `prenotazione`
  ADD CONSTRAINT `id_prenotante` FOREIGN KEY (`id_prenotante`) REFERENCES `Clienti` (`id_cliente`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

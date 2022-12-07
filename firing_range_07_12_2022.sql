-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 07 Gru 2022, 09:47
-- Wersja serwera: 10.4.11-MariaDB
-- Wersja PHP: 7.4.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `firing_range`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `caliber`
--

CREATE TABLE `caliber` (
  `caliber_id` tinyint(3) UNSIGNED NOT NULL,
  `caliber_name` varchar(32) NOT NULL,
  `price` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `caliber`
--

INSERT INTO `caliber` (`caliber_id`, `caliber_name`, `price`) VALUES
(1, '5.56×45 NATO', 4.5),
(2, '7.62×51 NATO', 8),
(3, '7.62×39', 3),
(4, '7.62×54R', 7),
(5, '5.7×28mm FN', 5),
(6, '4.6×30 HK', 5.5),
(7, '9×19 Parabellum', 2.5),
(8, '9×18 Makarov', 2),
(9, '.30-06 Springfield', 10),
(10, '.45 ACP', 3.5),
(11, '8mm Mauser', 10);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `client`
--

CREATE TABLE `client` (
  `client_id` smallint(6) UNSIGNED NOT NULL,
  `first_name` varchar(25) DEFAULT NULL,
  `last_name` varchar(32) DEFAULT NULL,
  `pesel` varchar(13) NOT NULL,
  `phone_directional` varchar(8) DEFAULT NULL,
  `phone_number` varchar(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `client`
--

INSERT INTO `client` (`client_id`, `first_name`, `last_name`, `pesel`, `phone_directional`, `phone_number`) VALUES
(1, 'Cezary', 'Krawczyk', '00291571018', '+48', '124651423'),
(2, 'Juliusz', 'Cezar', '97082950097', '+48', '325641741'),
(3, 'California', 'Friday', '95071986791', '+48', '225437432'),
(4, 'Daniel', 'Makowski', '56040821196', '+48', '357416872'),
(5, 'Florian', 'Kowalski', '91050666771', '+48', '542136982'),
(6, 'Ludwik', 'Jawrowski', '98012844794', '+48', '236874159'),
(7, 'Kacper', 'Klimkowski', '22010116894', '', '867409243');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `gun`
--

CREATE TABLE `gun` (
  `gun_id` smallint(4) UNSIGNED NOT NULL,
  `gun_name` varchar(32) NOT NULL,
  `caliber_id` tinyint(3) UNSIGNED NOT NULL,
  `manufacturer_id` tinyint(3) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `gun`
--

INSERT INTO `gun` (`gun_id`, `gun_name`, `caliber_id`, `manufacturer_id`) VALUES
(1, 'M4 Carbine', 1, 4),
(2, 'SCAR-L', 1, 5),
(3, 'SCAR-H', 2, 5),
(4, 'MP7A2', 6, 2),
(5, 'UMP45', 10, 2),
(6, 'UMP9', 7, 2),
(7, 'Five-seveN', 5, 5),
(8, 'P90', 5, 5),
(9, 'M1903 Springfield', 9, 1),
(10, 'Makarov PMM', 8, 3),
(11, 'Makarov PB', 8, 3),
(12, 'Mosin-Nagant M1891/30', 4, 6),
(13, 'Karabiner 98k', 11, 7),
(14, 'MP-443 Grach', 7, 3),
(15, 'USP .45 Elite', 10, 2),
(16, 'Glock 17', 7, 9),
(17, 'Glock 18C', 7, 9),
(18, 'P226R', 7, 8);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `manufacturer`
--

CREATE TABLE `manufacturer` (
  `manufacturer_id` tinyint(3) UNSIGNED NOT NULL,
  `manufacturer_name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `manufacturer`
--

INSERT INTO `manufacturer` (`manufacturer_id`, `manufacturer_name`) VALUES
(1, 'Springfield Armory'),
(2, 'Heckler & Koch'),
(3, 'Kalashnikov Concern'),
(4, 'Daniel Defense'),
(5, 'FN Herstal'),
(6, 'Imperial Tula Arms Plant'),
(7, 'Mauser'),
(8, 'SIG Sauer'),
(9, 'GLOCK');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `visit`
--

CREATE TABLE `visit` (
  `visit_id` smallint(6) UNSIGNED NOT NULL,
  `client_id` smallint(6) UNSIGNED NOT NULL,
  `gun_id` smallint(4) UNSIGNED NOT NULL,
  `amount_shot` smallint(4) UNSIGNED NOT NULL,
  `score` smallint(4) DEFAULT NULL,
  `date` date NOT NULL,
  `time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `visit`
--

INSERT INTO `visit` (`visit_id`, `client_id`, `gun_id`, `amount_shot`, `score`, `date`, `time`) VALUES
(1, 7, 7, 45, 421, '2022-11-08', '12:00:00'),
(2, 3, 18, 5, 0, '2022-11-08', '08:00:00'),
(3, 2, 9, 25, 242, '2022-11-09', '08:00:00'),
(4, 4, 1, 33, 197, '2022-11-09', '10:15:00'),
(5, 5, 17, 200, 576, '2022-11-11', '20:30:00'),
(6, 6, 13, 14, 139, '2022-11-13', '11:30:00'),
(7, 1, 16, 18, 145, '2022-11-21', '12:30:00'),
(8, 1, 10, 16, 125, '2022-11-21', '12:30:00'),
(9, 1, 18, 24, 98, '2022-11-21', '12:30:00'),
(10, 1, 15, 8, NULL, '2022-11-21', '12:30:00'),
(11, 7, 9, 30, 278, '2022-11-22', '21:15:00'),
(12, 7, 13, 30, 287, '2022-11-22', '21:15:00'),
(13, 7, 12, 30, 245, '2022-11-22', '21:15:00'),
(14, 2, 4, 80, 745, '2022-12-01', '06:30:00'),
(15, 2, 3, 55, 487, '2022-12-01', '06:30:00'),
(16, 2, 2, 90, 898, '2022-12-01', '12:00:00'),
(17, 2, 8, 150, NULL, '2022-12-02', '12:00:00');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `caliber`
--
ALTER TABLE `caliber`
  ADD PRIMARY KEY (`caliber_id`);

--
-- Indeksy dla tabeli `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`client_id`);

--
-- Indeksy dla tabeli `gun`
--
ALTER TABLE `gun`
  ADD PRIMARY KEY (`gun_id`),
  ADD KEY `gun_manufacturer_fk` (`manufacturer_id`),
  ADD KEY `gun_caliber_fk` (`caliber_id`);

--
-- Indeksy dla tabeli `manufacturer`
--
ALTER TABLE `manufacturer`
  ADD PRIMARY KEY (`manufacturer_id`);

--
-- Indeksy dla tabeli `visit`
--
ALTER TABLE `visit`
  ADD PRIMARY KEY (`visit_id`),
  ADD KEY `visit_client_fk` (`client_id`),
  ADD KEY `visit_gun_fk` (`gun_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `caliber`
--
ALTER TABLE `caliber`
  MODIFY `caliber_id` tinyint(3) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT dla tabeli `client`
--
ALTER TABLE `client`
  MODIFY `client_id` smallint(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT dla tabeli `gun`
--
ALTER TABLE `gun`
  MODIFY `gun_id` smallint(4) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT dla tabeli `manufacturer`
--
ALTER TABLE `manufacturer`
  MODIFY `manufacturer_id` tinyint(3) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT dla tabeli `visit`
--
ALTER TABLE `visit`
  MODIFY `visit_id` smallint(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `gun`
--
ALTER TABLE `gun`
  ADD CONSTRAINT `gun_caliber_fk` FOREIGN KEY (`caliber_id`) REFERENCES `caliber` (`caliber_id`) ON DELETE NO ACTION ON UPDATE CASCADE,
  ADD CONSTRAINT `gun_manufacturer_fk` FOREIGN KEY (`manufacturer_id`) REFERENCES `manufacturer` (`manufacturer_id`) ON DELETE NO ACTION ON UPDATE CASCADE;

--
-- Ograniczenia dla tabeli `visit`
--
ALTER TABLE `visit`
  ADD CONSTRAINT `visit_client_fk` FOREIGN KEY (`client_id`) REFERENCES `client` (`client_id`) ON DELETE NO ACTION ON UPDATE CASCADE,
  ADD CONSTRAINT `visit_gun_fk` FOREIGN KEY (`gun_id`) REFERENCES `gun` (`gun_id`) ON DELETE NO ACTION ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

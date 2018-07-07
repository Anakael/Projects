-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Хост: localhost
-- Время создания: Май 12 2017 г., 19:18
-- Версия сервера: 10.1.21-MariaDB
-- Версия PHP: 7.1.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `main_data_base`
--

-- --------------------------------------------------------

--
-- Структура таблицы `Applications`
--

CREATE TABLE `Applications` (
  `ID` int(10) UNSIGNED NOT NULL,
  `TypeDelivery` enum('Самостоятельный привоз - Самостоятельный вывоз','Доставка в цех - Самостоятельный вывоз','Самостоятельный привоз - Доставка до дома','Доставка в цех - Доставка до дома') COLLATE utf8_bin NOT NULL,
  `Price_For_Work` smallint(5) UNSIGNED NOT NULL,
  `Price_For_Delivery` smallint(5) UNSIGNED NOT NULL,
  `Price_Summary` smallint(5) UNSIGNED NOT NULL,
  `ID_Consumers` int(10) UNSIGNED NOT NULL,
  `Order_Date` date NOT NULL,
  `Status` enum('Ожидает доставки в цех','Доставлен в цех','В работе','Ожидает доставки клиенту') COLLATE utf8_bin NOT NULL,
  `Last_Update_Date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin ROW_FORMAT=COMPACT;

--
-- Дамп данных таблицы `Applications`
--

INSERT INTO `Applications` (`ID`, `TypeDelivery`, `Price_For_Work`, `Price_For_Delivery`, `Price_Summary`, `ID_Consumers`, `Order_Date`, `Status`, `Last_Update_Date`) VALUES
(1, 'Самостоятельный привоз - Самостоятельный вывоз', 2700, 4, 2704, 1, '0000-00-00', 'В работе', '2017-05-13');

-- --------------------------------------------------------

--
-- Структура таблицы `Config_AreaDelivery_Price`
--

CREATE TABLE `Config_AreaDelivery_Price` (
  `Area` enum('Московский','Кировский','Красносельский','') COLLATE utf8_bin NOT NULL,
  `Price` smallint(6) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Дамп данных таблицы `Config_AreaDelivery_Price`
--

INSERT INTO `Config_AreaDelivery_Price` (`Area`, `Price`) VALUES
('Московский', 500),
('Кировский', 600),
('Красносельский', 700);

-- --------------------------------------------------------

--
-- Структура таблицы `Config_Discount`
--

CREATE TABLE `Config_Discount` (
  `Discount` enum('Стандартная','Пенсионер инвалид ветеран','Скидка за 3 изделия','') COLLATE utf8_bin NOT NULL,
  `Value` smallint(5) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Дамп данных таблицы `Config_Discount`
--

INSERT INTO `Config_Discount` (`Discount`, `Value`) VALUES
('Стандартная', 10),
('Пенсионер инвалид ветеран', 5),
('Скидка за 3 изделия', 30);

-- --------------------------------------------------------

--
-- Структура таблицы `Config_Material_Price`
--

CREATE TABLE `Config_Material_Price` (
  `Material` enum('Синтетика','Шерсть','Синтетика + Шерсть','') COLLATE utf8_bin NOT NULL,
  `Price` smallint(6) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Дамп данных таблицы `Config_Material_Price`
--

INSERT INTO `Config_Material_Price` (`Material`, `Price`) VALUES
('Синтетика', 100),
('Шерсть', 200),
('Синтетика + Шерсть', 300);

-- --------------------------------------------------------

--
-- Структура таблицы `Config_TypeDelivery_Price`
--

CREATE TABLE `Config_TypeDelivery_Price` (
  `Type` enum('Самостоятельный привоз - Самостоятельный вывоз','Доставка в цех - Самостоятельный вывоз','Самостоятельный привоз - Доставка до дома','Доставка в цех - Доставка до дома') COLLATE utf8_bin NOT NULL,
  `Price` smallint(6) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Дамп данных таблицы `Config_TypeDelivery_Price`
--

INSERT INTO `Config_TypeDelivery_Price` (`Type`, `Price`) VALUES
('Самостоятельный привоз - Самостоятельный вывоз', 100),
('Доставка в цех - Самостоятельный вывоз', 200),
('Самостоятельный привоз - Доставка до дома', 300),
('Доставка в цех - Доставка до дома', 400);

-- --------------------------------------------------------

--
-- Структура таблицы `Consumers`
--

CREATE TABLE `Consumers` (
  `ID` int(10) UNSIGNED NOT NULL,
  `Name` varchar(100) COLLATE utf8_bin NOT NULL,
  `Phone_Number` varchar(20) COLLATE utf8_bin NOT NULL,
  `Area` enum('Московский','Кировский','Красносельский','') COLLATE utf8_bin NOT NULL,
  `Address` varchar(100) COLLATE utf8_bin NOT NULL,
  `Additional_Discount` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin ROW_FORMAT=COMPACT;

--
-- Дамп данных таблицы `Consumers`
--

INSERT INTO `Consumers` (`ID`, `Name`, `Phone_Number`, `Area`, `Address`, `Additional_Discount`) VALUES
(1, 'Щемель Дмитрий Артемьевич', '+79999999995', 'Кировский', 'Есенина, каруселина', 0);

-- --------------------------------------------------------

--
-- Структура таблицы `Materials`
--

CREATE TABLE `Materials` (
  `ID` int(20) UNSIGNED NOT NULL,
  `Material` enum('Синтетика','Шерсть','Синтетика + Шерсть','') COLLATE utf8_bin NOT NULL,
  `Size` tinyint(3) UNSIGNED NOT NULL,
  `ID_Application` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin ROW_FORMAT=COMPACT;

--
-- Дамп данных таблицы `Materials`
--

INSERT INTO `Materials` (`ID`, `Material`, `Size`, `ID_Application`) VALUES
(1, 'Шерсть', 5, 1),
(2, 'Шерсть', 5, 1),
(3, 'Шерсть', 5, 1);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `Applications`
--
ALTER TABLE `Applications`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Applications_ibfk_1` (`ID_Consumers`);

--
-- Индексы таблицы `Config_AreaDelivery_Price`
--
ALTER TABLE `Config_AreaDelivery_Price`
  ADD UNIQUE KEY `Area` (`Area`),
  ADD UNIQUE KEY `Area_2` (`Area`);

--
-- Индексы таблицы `Config_Discount`
--
ALTER TABLE `Config_Discount`
  ADD UNIQUE KEY `Discount` (`Discount`);

--
-- Индексы таблицы `Config_Material_Price`
--
ALTER TABLE `Config_Material_Price`
  ADD UNIQUE KEY `Material` (`Material`);

--
-- Индексы таблицы `Config_TypeDelivery_Price`
--
ALTER TABLE `Config_TypeDelivery_Price`
  ADD UNIQUE KEY `Type` (`Type`);

--
-- Индексы таблицы `Consumers`
--
ALTER TABLE `Consumers`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `Phone_Number` (`Phone_Number`);

--
-- Индексы таблицы `Materials`
--
ALTER TABLE `Materials`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Materials_ibfk_1` (`ID_Application`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `Applications`
--
ALTER TABLE `Applications`
  MODIFY `ID` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT для таблицы `Consumers`
--
ALTER TABLE `Consumers`
  MODIFY `ID` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT для таблицы `Materials`
--
ALTER TABLE `Materials`
  MODIFY `ID` int(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `Applications`
--
ALTER TABLE `Applications`
  ADD CONSTRAINT `Applications_ibfk_1` FOREIGN KEY (`ID_Consumers`) REFERENCES `Consumers` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Materials`
--
ALTER TABLE `Materials`
  ADD CONSTRAINT `Materials_ibfk_1` FOREIGN KEY (`ID_Application`) REFERENCES `Applications` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

---------------------------------------------------------------------------------------------------
--
-- Title       : memori_lib
-- Design      : lab21
-- Author      : toshiba
-- Company     : laptop
--
----------------------------------------------------------------------------------------------------
--
-- Description : Fisier generat cu utilitarul mem_wr
--
---------------------------------------------------------------------------------------------------

	
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity rom256x8 is	 
	port (adrese : in std_logic_vector (7 downto 0);
	date : out std_logic_vector (7 downto 0);
	cs,oe: in std_logic);
end rom256x8;

architecture rom256x8_a of rom256x8 is
--definirea unor tipuri de date
type matrice_rom is array (0 to 256) of bit_vector (7 downto 0);
--definirea unui vector de constante care variable repreyenta continutul memoriei ROM
--clauza others este folosita pentru initializarea tuturor celorlalte locatii
constant valori_rom : matrice_rom :=
(
--Aici datele sunt adaugate automat! Nu sterge aceasta sectiune!!
--
00 => X"01",
01 => X"23",
02 => X"34",

others => X"ff");

begin
	comp_rom1 : process (adrese,cs,oe)
--indexul din vector	
	variable index : integer := 0;
	begin 
		if(cs='1' or oe='1') then
			date <= "ZZZZZZZZ";
		else
			index := 0;
--indexul este obtinut in functie de valoarea din adresa 
			for i in adrese'range loop
				if adrese(i) = '1' then
					index := index + 2 ** i;
				end if;
			end loop;
--functia To_StdLogicVector transforma un vector de tipul bit_vector intr-unul std_logic_vector
--apartine pachetului IEEE_std_logic_1164
			date <= To_StdLogicVector(valori_rom(index));
		end if;	
	end process comp_rom1;

end rom256x8_a;
module dcache(d_hit, d_miss, d_read, d_write, d_ratio, tl, found,
index, tag, nevent, offset, mesi_state, line_lru, mesi_mru, iteration);

output real d_hit; 
output real d_miss;
output real d_read; 
output real d_write; 
output real d_ratio; 
output logic [95:0] tl; 
output logic found; 
output logic [23:0] line_lru; 
output logic [15:0] mesi_state; 
output logic [1:0] mesi_mru; 
input logic [13:0] index; 
input logic [11:0] tag; 
input logic [3:0] nevent; 
input logic [5:0] offset; 
input logic [31:0] iteration; 

logic [95:0] d_cache [0:16383]; 
logic [11:0] t_way_one; 
logic [11:0] t_way_two; 
logic [11:0] t_way_three;
logic [11:0] t_way_four;
logic [11:0] t_way_five; 
logic [11:0] t_way_six; 
logic [11:0] t_way_seven;
logic [11:0] t_way_eight;


logic [2:0] way_mru; 
logic [23:0] cache_lru [0:16383]; 
logic [2:0] all_lru [0:7]; 
logic [2:0] least_lru; 
logic [2:0] way_index; 
logic [2:0] mru_index; 
logic [2:0] lru_way_one;
logic [2:0] lru_way_two;
logic [2:0] lru_way_three;
logic [2:0] lru_way_four;
logic [2:0] lru_way_five;
logic [2:0] lru_way_six;
logic [2:0] lru_way_seven;
logic [2:0] lru_way_eight; 

logic [15:0] mesi_data [0:16383]; 
logic [1:0] all_mesi [0:7]; 
logic [1:0] mesi_way_one;
logic [1:0] mesi_way_two;
logic [1:0] mesi_way_three;
logic [1:0] mesi_way_four;
logic [1:0] mesi_way_five;
logic [1:0] mesi_way_six;
logic [1:0] mesi_way_seven;
logic [1:0] mesi_way_eight; 
logic [1:0] mesi_index; 
logic [2:0] mesi_lru_index; 
logic invalid = 1'b0; 

integer i, j;

parameter I = 2'b00; 
parameter S = 2'b01; 
parameter E = 2'b10; 
parameter M = 2'b11; 

initial begin

  foreach(all_lru[i]) begin
	  all_lru[i] = i;
	  all_mesi[i] = I;
  end
  line_lru = {all_lru[0], all_lru[1], all_lru[2], all_lru[3], all_lru[4], all_lru[5], all_lru[6], all_lru[7]};
  mesi_state = {all_mesi[0], all_mesi[1], all_mesi[2], all_mesi[3], all_mesi[4], all_mesi[5], all_mesi[6], all_mesi[7]};

  for(i = 0; i < 16384; i = i + 1) begin
    cache_lru[i] = line_lru; 
    mesi_data[i] = mesi_state; 
  end
  d_hit = 0; 
  d_miss = 0;
  d_read = 0;
  d_write = 0;
  d_ratio = 0;
end

always @(nevent, index, tag, offset, iteration)
begin
if (nevent == 8) begin 
  
  foreach(all_lru[i]) begin
	  all_lru[i] = i;
	  all_mesi[i] = I;
  end
  line_lru = {all_lru[0], all_lru[1], all_lru[2], all_lru[3], all_lru[4], all_lru[5], all_lru[6], all_lru[7]};
  mesi_state = {all_mesi[0], all_mesi[1], all_mesi[2], all_mesi[3], all_mesi[4], all_mesi[5], all_mesi[6], all_mesi[7]};

  for(i = 0; i < 16384; i = i + 1) begin
    cache_lru[i] = line_lru;
    mesi_data[i] = mesi_state;
  end
  d_hit = 0;
  d_miss = 0;
  d_read = 0;
  d_write = 0;
  d_ratio = 0;

  for(j = 0; j < 16384; j = j + 1) begin
    d_cache[j] = tl; 
  end
end


else if(nevent == 0 || nevent == 1 || nevent == 3 || nevent == 4 || nevent == 9) begin
all_lru[0] = cache_lru[index][23:21]; 
all_lru[1] = cache_lru[index][20:18];
all_lru[2] = cache_lru[index][17:15];
all_lru[3] = cache_lru[index][14:12];
all_lru[4] = cache_lru[index][11:9];
all_lru[5] = cache_lru[index][8:6];
all_lru[6] = cache_lru[index][5:3];
all_lru[7] = cache_lru[index][2:0];

mesi_state = mesi_data[index]; 
all_mesi[0] = mesi_state[15:14]; 
all_mesi[1] = mesi_state[13:12];
all_mesi[2] = mesi_state[11:10];
all_mesi[3] = mesi_state[9:8];
all_mesi[4] = mesi_state[7:6];
all_mesi[5] = mesi_state[5:4];
all_mesi[6] = mesi_state[3:2];
all_mesi[7] = mesi_state[1:0];

invalid = 0; 
way_index = 0; 
mesi_lru_index = 7; 

for(i = 0; i < 8; i = i + 1) begin
  if(all_mesi[i] == I && all_lru[i] <= mesi_lru_index) begin 
    invalid = 1;
    mesi_lru_index = all_lru[i];
    way_index = i;
  end
end


if(invalid == 0) begin
  least_lru = all_lru[0]; 
  way_index = 0;
  for(i = 1; i < 8; i = i + 1) begin
    if(all_lru[i] < least_lru) begin
      least_lru = all_lru[i];
      way_index = i;
    end
  end
end

  tl = d_cache[index]; 
  t_way_one = tl[95:84]; 
  t_way_two = tl[83:72];
  t_way_three = tl[71:60];
  t_way_four = tl[59:48];
  t_way_five = tl[47:36];
  t_way_six = tl[35:24];
  t_way_seven = tl[23:12];
  t_way_eight = tl[11:0];
  
  if (tag == t_way_one || tag == t_way_two || tag == t_way_three || tag == t_way_four || tag == t_way_five || tag == t_way_six || tag == t_way_seven || tag == t_way_eight) begin
	  found = 1;
	  d_hit += 1;
	  if (tag == t_way_one) way_mru = 0;
	  else if (tag == t_way_two) way_mru = 1;
	  else if (tag == t_way_three) way_mru = 2;
	  else if (tag == t_way_four) way_mru = 3;
	  else if (tag == t_way_five) way_mru = 4;
	  else if (tag == t_way_six) way_mru = 5;
	  else if (tag == t_way_seven) way_mru = 6;
	  else if (tag == t_way_eight) way_mru = 7;
  end else begin
          way_mru = way_index; 
          found = 0; 
          d_miss = d_miss + 1; 
          case(way_index) 
            0: t_way_one = tag;
            1: t_way_two = tag;
            2: t_way_three = tag;
            3: t_way_four = tag;
            4: t_way_five = tag;
            5: t_way_six = tag;
            6: t_way_seven = tag;
            7: t_way_eight = tag;
  	    default;
          endcase
  end
  
  tl = {t_way_one, t_way_two, t_way_three, t_way_four, t_way_five, t_way_six, t_way_seven, t_way_eight}; 
  d_cache[index] = tl; 

  d_ratio = d_hit/(d_hit + d_miss); 

  mesi_index = all_mesi[way_mru]; 
  all_mesi[way_mru] = mesi(mesi_index, nevent, found);
  
  mesi_state = {all_mesi[0], all_mesi[1], all_mesi[2], all_mesi[3], all_mesi[4], all_mesi[5], all_mesi[6], all_mesi[7]};
  mesi_way_one = mesi_state[15:14];
  mesi_way_two = mesi_state[13:12];
  mesi_way_three = mesi_state[11:10];
  mesi_way_four = mesi_state[9:8];
  mesi_way_five = mesi_state[7:6];
  mesi_way_six = mesi_state[5:4];
  mesi_way_seven = mesi_state[3:2];
  mesi_way_eight = mesi_state[1:0];
  mesi_data[index] = mesi_state; 
  mesi_mru = all_mesi[way_mru]; 

  mru_index = all_lru[way_mru]; 
  for(i = 0; i < 8; i = i + 1) begin
    if (all_lru[i] > mru_index) begin 
      all_lru[i] = all_lru[i] - 1; 
    end
    else begin
      all_lru[i] = all_lru[i]; 
    end
  end

  all_lru[way_mru] = 7; 
  lru_way_one = all_lru[0]; 
  lru_way_two = all_lru[1];
  lru_way_three = all_lru[2];
  lru_way_four = all_lru[3];
  lru_way_five = all_lru[4];
  lru_way_six = all_lru[5];
  lru_way_seven = all_lru[6];
  lru_way_eight = all_lru[7];

  line_lru = {lru_way_one, lru_way_two, lru_way_three, lru_way_four, lru_way_five, lru_way_six, lru_way_seven, lru_way_eight};
  cache_lru[index] = line_lru; 

if (nevent == 0) d_read += 1;
else if (nevent == 1) d_write +=1;

end
end

function logic [1:0] mesi(logic [1:0] mesi_index, logic [3:0] nevent, logic found);
case(mesi_index) 

  0: begin 
    if(nevent == 1) begin 
      return 3; 
    end
    else if(nevent == 0 && found == 1) begin 
      return 1; 
    end
    else if(nevent == 0 && found == 0) begin 
      return 2; 
    end
  end

  1: begin 
    if(nevent == 1 && found == 0) begin 
      return 3; 
    end
    else if(nevent == 0) begin 
      return 1;
    end
  end

  2: begin 
    if(nevent == 1) begin 
      return 3; 
    end
    else if(nevent == 0 && found == 1) begin 
      return 1; 
    end
    else if(nevent == 0 && found == 0) begin 
      return 2; 
    end
    else if(nevent == 4) begin 
      return 0; 
    end
  end

  3: begin 
    if(nevent == 0 || nevent == 1) begin
      return 3; 
    end
    else if(nevent == 4) begin
      return 0; 
    end
  end
  endcase
endfunction 

endmodule

module icache(i_hit, i_miss, i_read, i_ratio, tl, line_lru, found, index, tag, nevent, offset, iteration);

output real i_hit;
output real i_miss; 
output real i_read;
output real i_ratio;
output logic [47:0] tl;
output logic found;
output logic [7:0] line_lru;
input logic [13:0] index;
input logic [11:0] tag;
input logic [3:0] nevent;
input logic [5:0] offset;
input logic [31:0] iteration;

logic [1:0] way_mru;
logic [47:0] i_cache [0:16383];
logic [11:0] t_way_one;
logic [11:0] t_way_two;
logic [11:0] t_way_three;
logic [11:0] t_way_four;
logic [7:0] cache_lru [0:16383];
logic [1:0] all_lru [0:3];
logic [1:0] least_lru;
logic [1:0] way_index;
logic [1:0] mru_index;

logic [1:0] lru_way_one, lru_way_two, lru_way_three, lru_way_four;

integer i;

initial begin

  foreach(all_lru[i]) all_lru[i] = i;

  line_lru = {all_lru[0], all_lru[1], all_lru[2], all_lru[3]};

  for(i = 0; i < 16384; i = i + 1) begin
    cache_lru[i] = line_lru;
  end

  i_hit = 0;
  i_miss = 0;
  i_read = 0;
  i_ratio = 0;
end

always @(index, tag, nevent, offset, iteration) begin
if(nevent == 8) begin
  
  foreach(all_lru[i]) all_lru[i] = i;
  line_lru = {all_lru[0], all_lru[1], all_lru[2], all_lru[3]};
  
  i_hit = 0;
  i_miss = 0;
  i_read = 0;
  i_ratio = 0;
  tl = 48'bx;

  for(i = 0; i < 16384; i = i + 1) begin
    cache_lru[i] = line_lru;
    i_cache[i] = tl;
  end
end
else if(nevent == 2) begin

  i_read = i_read + 1;

  all_lru[0] = cache_lru[index][7:6];
  all_lru[1] = cache_lru[index][5:4];
  all_lru[2] = cache_lru[index][3:2];
  all_lru[3] = cache_lru[index][1:0];

  least_lru = all_lru[0];
  way_index = 2'b0;
  for(i = 1; i < 4; i = i + 1) begin
    if(all_lru[i] < least_lru) begin
      least_lru = all_lru[i];
      way_index = i;
    end
end

  tl = i_cache[index];
  t_way_one = tl[47:36];
  t_way_two = tl[35:24];
  t_way_three = tl[23:12];
  t_way_four = tl[11:0];
  if (tag == t_way_one || tag == t_way_two || tag == t_way_three || tag == t_way_four) begin
	  found = 1;
	  i_hit += 1;
	  if (tag == t_way_one) way_mru = 0;
	  else if (tag == t_way_two) way_mru = 1;
	  else if (tag == t_way_three) way_mru = 2;
	  else if (tag == t_way_four) way_mru = 3;
  end else begin
	way_mru = way_index;	  
          found = 0;
          i_miss = i_miss + 1;
          case(way_index)
            0: t_way_one = tag;
            1: t_way_two = tag;
            2: t_way_three = tag;
            3: t_way_four = tag;
	    default;
	  endcase
  end
  tl = {t_way_one, t_way_two, t_way_three, t_way_four};
  i_cache[index] = tl;

  i_ratio = i_hit/(i_hit + i_miss);

    mru_index = all_lru[way_mru];
    for(i = 0; i < 4; i = i + 1) begin
      if (all_lru[i] > mru_index) begin
        all_lru[i] = all_lru[i] - 1;
      end
      else begin
        all_lru[i] = all_lru[i];
      end
    end

    all_lru[way_mru] = 2'b11;
    lru_way_one = all_lru[0];
    lru_way_two = all_lru[1];
    lru_way_three = all_lru[2];
    lru_way_four = all_lru[3];
    line_lru = {lru_way_one, lru_way_two, lru_way_three, lru_way_four};
    cache_lru[index] = line_lru;


end
end

endmodule

module icache(i_hit, i_miss, i_read, i_ratio, tl, line_lru, found, index, tag, nevent, offset, iteration);

output real i_hit;
output real i_miss;
output real i_read;
output real i_ratio;
output logic [47:0] tl;
output logic found;
output logic [7:0] line_lru;
input logic [13:0] index;
input logic [11:0] tag;
input logic [3:0] nevent;
input logic [5:0] offset;
input logic [31:0] iteration;

logic [1:0] way_mru;
logic [47:0] i_cache [0:16383];
logic [11:0] t_way_one;
logic [11:0] t_way_two;
logic [11:0] t_way_three;
logic [11:0] t_way_four;
logic [7:0] cache_lru [0:16383];
logic [1:0] all_lru [0:3];
logic [1:0] least_lru;
logic [1:0] way_index;
logic [1:0] mru_index;

logic [1:0] lru_way_one;
logic [1:0] lru_way_two;
logic [1:0] lru_way_three;
logic [1:0] lru_way_four;

integer i;

initial begin

  foreach(all_lru[i]) all_lru[i] = i;

  line_lru = {all_lru[0], all_lru[1], all_lru[2], all_lru[3]};

  for(i = 0; i < 16384; i = i + 1) begin
    cache_lru[i] = line_lru;
  end

  i_hit = 0;
  i_miss = 0;
  i_read = 0;
  i_ratio = 0;
end

always @(index, tag, nevent, offset, iteration) begin
if(nevent == 8) begin
  
  foreach(all_lru[i]) all_lru[i] = i;
  line_lru = {all_lru[0], all_lru[1], all_lru[2], all_lru[3]};
  
  i_hit = 0;
  i_miss = 0;
  i_read = 0;
  i_ratio = 0;
  tl = 48'bx;

  for(i = 0; i < 16384; i = i + 1) begin
    cache_lru[i] = line_lru;
    i_cache[i] = tl;
  end
end
else if(nevent == 2) begin

  i_read = i_read + 1;

  all_lru[0] = cache_lru[index][7:6];
  all_lru[1] = cache_lru[index][5:4];
  all_lru[2] = cache_lru[index][3:2];
  all_lru[3] = cache_lru[index][1:0];

  least_lru = all_lru[0];
  way_index = 2'b0;
  for(i = 1; i < 4; i = i + 1) begin
    if(all_lru[i] < least_lru) begin
      least_lru = all_lru[i];
      way_index = i;
    end
end

  tl = i_cache[index];
  t_way_one = tl[47:36];
  t_way_two = tl[35:24];
  t_way_three = tl[23:12];
  t_way_four = tl[11:0];
  if (tag == t_way_one || tag == t_way_two || tag == t_way_three || tag == t_way_four) begin
	  found = 1;
	  i_hit += 1;
	  if (tag == t_way_one) way_mru = 0;
	  else if (tag == t_way_two) way_mru = 1;
	  else if (tag == t_way_three) way_mru = 2;
	  else if (tag == t_way_four) way_mru = 3;
  end else begin
	way_mru = way_index;	  
          found = 0;
          i_miss = i_miss + 1;
          case(way_index)
            0: t_way_one = tag;
            1: t_way_two = tag;
            2: t_way_three = tag;
            3: t_way_four = tag;
	    default;
	  endcase
  end
  tl = {t_way_one, t_way_two, t_way_three, t_way_four};
  i_cache[index] = tl;

  i_ratio = i_hit/(i_hit + i_miss);
  
    mru_index = all_lru[way_mru];
    for(i = 0; i < 4; i = i + 1) begin
      if (all_lru[i] > mru_index) begin
        all_lru[i] = all_lru[i] - 1;
      end
      else begin
        all_lru[i] = all_lru[i];
      end
    end

    all_lru[way_mru] = 2'b11;
    lru_way_one = all_lru[0];
    lru_way_two = all_lru[1];
    lru_way_three = all_lru[2];
    lru_way_four = all_lru[3];
    line_lru = {lru_way_one, lru_way_two, lru_way_three, lru_way_four};
    cache_lru[index] = line_lru;


end
end

endmodule

module display(mode, index, address, nevent, tag, offset, data_tl, found_data, data_lru, mesi_state, d_hit, d_miss,
d_read, d_write, d_ratio, i_hit, i_miss, i_read, i_cache_write, i_ratio, instruction_tl, instruction_lru, mesi_mru, iteration);

input logic [13:0] index;
input logic mode;
input logic [35:0] address;
input logic [3:0] nevent;
input logic [11:0] tag;
input logic [5:0] offset;
input logic [31:0] iteration;

input logic [95:0] data_tl;
input logic found_data;
input logic [23:0] data_lru;
input logic [15:0] mesi_state;
input real d_hit, d_miss, d_read, d_write, d_ratio;
input logic [1:0] mesi_mru;
logic [11:0] tag_way_data1;
logic [11:0] tag_way_data2;
logic [11:0] tag_way_data3;
logic [11:0] tag_way_data4;
logic [11:0] tag_way_data5;
logic [11:0] tag_way_data6;
logic [11:0] tag_way_data7;
logic [11:0] tag_way_data8;
logic [2:0] LRU_way_data1;
logic [2:0] LRU_way_data2;
logic [2:0] LRU_way_data3;
logic [2:0] LRU_way_data4;
logic [2:0] LRU_way_data5;
logic [2:0] LRU_way_data6;
logic [2:0] LRU_way_data7;
logic [2:0] LRU_way_data8;
logic [1:0] mesi_way_one;
logic [1:0] mesi_way_two;
logic [1:0] mesi_way_three;
logic [1:0] mesi_way_four;
logic [1:0] mesi_way_five;
logic [1:0] mesi_way_six;
logic [1:0] mesi_way_seven;
logic [1:0] mesi_way_eight;

input real i_hit, i_miss, i_read, i_cache_write, i_ratio;
input logic [47:0] instruction_tl;
input logic [7:0] instruction_lru;
logic [11:0] tag_wayinst1;
logic [11:0] tag_wayinst2;
logic [11:0] tag_wayinst3;
logic [11:0] tag_wayinst4;
logic [1:0] LRU_way_inst1;
logic [1:0] LRU_way_inst2;
logic [1:0] LRU_way_inst3;
logic [1:0] LRU_way_inst4;

always @(nevent, index, tag, offset, iteration) begin

tag_way_data1 = data_tl[95:84];
tag_way_data2 = data_tl[83:72];
tag_way_data3 = data_tl[71:60];
tag_way_data4 = data_tl[59:48];
tag_way_data5 = data_tl[47:36];
tag_way_data6 = data_tl[35:24];
tag_way_data7 = data_tl[23:12];
tag_way_data8 = data_tl[11:0];

tag_wayinst1 = instruction_tl[47:36];
tag_wayinst2 = instruction_tl[35:24];
tag_wayinst3 = instruction_tl[23:12];
tag_wayinst4 = instruction_tl[11:0];

LRU_way_data1 = data_lru[23:21];
LRU_way_data2 = data_lru[20:18];
LRU_way_data3 = data_lru[17:15];
LRU_way_data4 = data_lru[14:12];
LRU_way_data5 = data_lru[11:9];
LRU_way_data6 = data_lru[8:6];
LRU_way_data7 = data_lru[5:3];
LRU_way_data8 = data_lru[2:0];

LRU_way_inst1 = instruction_lru[7:6];
LRU_way_inst2 = instruction_lru[5:4];
LRU_way_inst3 = instruction_lru[3:2];
LRU_way_inst4 = instruction_lru[1:0];

mesi_way_one = mesi_state[15:14];
mesi_way_two = mesi_state[13:12];
mesi_way_three = mesi_state[11:10];
mesi_way_four = mesi_state[9:8];
mesi_way_five = mesi_state[7:6];
mesi_way_six = mesi_state[5:4];
mesi_way_seven = mesi_state[3:2];
mesi_way_eight = mesi_state[1:0];


address = {tag,index,offset};
  if(mode == 0) begin 
    if(nevent == 9)begin
        stats(d_read, d_write, d_hit, d_miss, d_ratio, tag_way_data1, tag_way_data2, tag_way_data3, tag_way_data4, tag_way_data5, tag_way_data6, tag_way_data7, tag_way_data8, mesi_way_one, mesi_way_two, mesi_way_three, mesi_way_four, mesi_way_five, mesi_way_six, mesi_way_seven, mesi_way_eight, LRU_way_data1, LRU_way_data2, LRU_way_data3, LRU_way_data4, LRU_way_data5, LRU_way_data6, LRU_way_data7, LRU_way_data8, i_read, i_cache_write, i_hit, i_miss, i_ratio, index, tag_wayinst1, tag_wayinst2, tag_wayinst3, tag_wayinst4, LRU_way_inst1, LRU_way_inst2, LRU_way_inst3, LRU_way_inst4);
    end
  end
  else if(mode == 1) begin
    if(nevent == 9)begin
	stats(d_read, d_write, d_hit, d_miss, d_ratio, tag_way_data1, tag_way_data2, tag_way_data3, tag_way_data4, tag_way_data5, tag_way_data6, tag_way_data7, tag_way_data8, mesi_way_one, mesi_way_two, mesi_way_three, mesi_way_four, mesi_way_five, mesi_way_six, mesi_way_seven, mesi_way_eight, LRU_way_data1, LRU_way_data2, LRU_way_data3, LRU_way_data4, LRU_way_data5, LRU_way_data6, LRU_way_data7, LRU_way_data8, i_read, i_cache_write, i_hit, i_miss, i_ratio, index, tag_wayinst1, tag_wayinst2, tag_wayinst3, tag_wayinst4, LRU_way_inst1, LRU_way_inst2, LRU_way_inst3, LRU_way_inst4);
                end
    else if((nevent == 1 && mesi_mru == 3) | (nevent == 1 && mesi_mru == 0))begin
      $display("Write data to L2 cache: %0h \n", address);
        end
	else if (nevent == 1 && found_data == 0) begin
		$display("write miss from l2 cache: %0h \n", address);
		end
    else if(nevent == 2)begin
      $display("Read data from L2 cache: %0h \n", address);
            end
    else if(nevent == 4) begin
      $display("Return data to L2 cache: %0h \n", address);
            end
  end
end



task stats(real d_read, real d_write, real d_hit, real d_miss, real d_ratio, 
logic [11:0] tag_way_data1, logic [11:0] tag_way_data2, logic [11:0] tag_way_data3, logic [11:0] tag_way_data4, logic [11:0] tag_way_data5, logic [11:0] tag_way_data6, logic [11:0] tag_way_data7, 
logic [11:0] tag_way_data8, logic [1:0] mesi_way_one, logic [1:0] mesi_way_two, logic [1:0] mesi_way_three, logic [1:0] mesi_way_four, logic [1:0] mesi_way_five, logic [1:0] mesi_way_six, logic [1:0] mesi_way_seven, 
logic [1:0] mesi_way_eight, logic [2:0] LRU_way_data1, logic [2:0] LRU_way_data2, logic [2:0] LRU_way_data3, logic [2:0] LRU_way_data4, logic [2:0] LRU_way_data5, logic [2:0] LRU_way_data6, 
logic [2:0] LRU_way_data7, logic [2:0] LRU_way_data8, real i_read, real i_cache_write, real i_hit, real i_miss, real i_ratio, 
logic [13:0] index, logic [11:0] tag_wayinst1, logic [11:0] tag_wayinst2, logic [11:0] tag_wayinst3, logic [11:0] tag_wayinst4, logic [1:0] LRU_way_inst1, 
logic [1:0] LRU_way_inst2, logic [1:0] LRU_way_inst3, logic [1:0] LRU_way_inst4);

	static string MAP[int] = '{default: "U", 0: "I", 1: "S", 2: "E", 3: "M"};

        $display("Using mode 1\n");
        $display("*******************     Statistics       ********************\n");
        $display("******* DATA CACHE \n");
        $display("| Reads: \t%0d\n| Writes: \t%0d \n| Hits: \t%0d\n| Misses: \t%0d\n| Hit Ratio: \t%1.2f \n", d_read, d_write, d_hit, d_miss, d_ratio);
        $display("*** CONTENT");
        $display("  Way:  Way-1 | Way-2 | Way-3 | Way-4 | Way-5 | Way-6 | Way-7 | Way-8 |");
        $display("Index:   %h\t|  %h\t|  %h\t|  %h\t|  %h\t|  %h\t|  %h\t|  %h\t|", tag_way_data1, tag_way_data2, tag_way_data3, tag_way_data4, tag_way_data5, tag_way_data6, tag_way_data7, tag_way_data8);
        $display("  LRU:   %b\t|  %b\t|  %b\t|  %b\t|  %b\t|  %b\t|  %b\t|  %b\t|", LRU_way_data1, LRU_way_data2, LRU_way_data3, LRU_way_data4, LRU_way_data5, LRU_way_data6, LRU_way_data7, LRU_way_data8);
        $display(" MESI:    %s\t|   %s\t|   %s\t|   %s\t|   %s\t|   %s\t|   %s\t|   %s\t|", MAP[mesi_way_one], MAP[mesi_way_two], MAP[mesi_way_three], MAP[mesi_way_four], MAP[mesi_way_five], MAP[mesi_way_six], MAP[mesi_way_seven], MAP[mesi_way_eight]);
		
        $display("\n******* INSTRUCTION CACHE \n");
        $display("| Reads: \t%0d\n| Writes: \t%0d \n| Hits: \t%0d \n| Misses: \t%0d \n| Hit Ratio: \t%1.2f \n", i_read, i_cache_write, i_hit, i_miss, i_ratio);
        $display("Index: %b (%h) \n",index, index);
        $display("*** CONTENT");
        $display("Way:    Way-1\t| Way-2 | Way-3 | Way-4 |");
        $display("Index:   %h\t|  %h\t|  %h\t|  %h\t|", tag_wayinst1, tag_wayinst2, tag_wayinst3, tag_wayinst4);
        $display("LRU:     %b\t|  %b\t|  %b\t|  %b\t|", LRU_way_inst1, LRU_way_inst2, LRU_way_inst3, LRU_way_inst4);
        $display("\n*******************     End Statistics       ********************\n");
endtask
endmodule


module top;

logic clk; 
logic mode;

string filename;
logic [31:0] data [100000:0];
logic [35:0] address [100000:0];

logic [5:0] offset; 
logic [13:0] index; 
logic [11:0] tag;   
logic [3:0] nevent;

initial clk = 1'b1; 
always #5 clk = ~clk;

logic [95:0] data_tl; 
logic [15:0] mesi_state; 
logic [1:0] mesi_mru; 
logic [23:0] data_lru; 
logic dhm_count; 

real d_hit;
real d_miss;
real d_read;
real d_write;
real d_ratio;
logic ihm_count; 
logic [7:0] instruction_lru; 
logic [47:0] instruction_tl;
real i_hit;
real i_miss;
real i_read;
real i_ratio; 
integer i, j, k; 

	int fd, iel, dan; 
	string line, mode_string, data_string;
dcache data_cache(
  .d_hit(d_hit), 
  .d_miss(d_miss), 
  .d_read(d_read), 
  .d_write(d_write), 
  .d_ratio(d_ratio), 
  .tl(data_tl), 
  .found(dhm_count),
  .index(index),
  .tag(tag),
  .nevent(nevent), 
  .offset(offset),
  .mesi_state(mesi_state),
  .line_lru(data_lru),
  .mesi_mru(mesi_mru),
  .iteration(k));

icache instruction_cache(
  .i_hit(i_hit), 
  .i_miss(i_miss),
  .i_read(i_read),
  .i_ratio(i_ratio), 
  .tl(instruction_tl), 
  .line_lru(instruction_lru), 
  .found(ihm_count), 
  .index(index), 
  .tag(tag), 
  .nevent(nevent), 
  .offset(offset), 
  .iteration(k));

display d1(
  .mode(mode),
  .index(index), 
  .address(address[k]),
  .nevent(nevent), 
  .tag(tag),
  .offset(offset), 
  .data_tl(data_tl),
  .instruction_tl(instruction_tl),
  .found_data(found_data), 
  .data_lru(data_lru), 
  .instruction_lru(instruction_lru), 
  .mesi_state(mesi_state), 
  .d_hit(d_hit), 
  .d_miss(d_miss), 
  .d_read(d_read),  
  .d_write(d_write), 
  .d_ratio(d_ratio), 
  .i_hit(i_hit), 
  .i_miss(i_miss), 
  .i_read(i_read), 
  .i_ratio(i_ratio), 
  .mesi_mru(mesi_mru), 
  .iteration(k));


initial begin

if ($test$plusargs("advanced")) mode = 1;
else mode = 0;

if ($value$plusargs("filename=%s", filename))
fd = $fopen(filename, "r");
	
k = 0;
nevent = 0;
while (!$feof(fd)) begin
	//grab each line and separate mode from address
	$fgets(line, fd);
	if(line == "") break;
	$sscanf(line, "%s %s", mode_string, data_string);	
	//convert from ASCII to integer for mode and binary for address 
	address[k] = {mode_string.atoi(), data_string.atohex()};
	k +=1;
	if(k >= 50000) break;
end
address[k] = 'hx;
go(address);
end
/*go takes each line and parses into offset, index, tag, and nevent to be
sent to the three submodules: dcache, icache, and display for operation
*/
task go(logic [35:0] address [100000:0]);
	for(i = 0 ; i < 50000 ; i = i + 1) begin 
		#100;
		if(address[i+1] === 36'hx || k == 49999) begin 
			nevent = 9;
			offset = address[i][5:0];
			index = address[i][19:6];
			tag = address[i][31:20];
			#100
			$stop; 
		end else if(address[i] !== 36'bx) begin 
			offset = address[i][5:0];
			index = address[i][19:6];
			tag = address[i][31:20];
			nevent = address[i][35:32];
		end
	end	
endtask


endmodule

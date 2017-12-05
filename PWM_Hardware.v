module pmw(clk, rst_n, pulse_period, pulse_width,pwm_out);
parameter regwidth = 12;
input wire clk;
input wire rst_n;
input wire [regwidth-1:0] pulse_period;
input wire [regwidth-1:0] pulse_width;
output pwm_out;
wire rst;
reg [regwidth-1:0] ticks_d, ticks_q;
reg pwm_d, pwm_q;
assign rst = ~rst_n;
always@(*)
begin
	ticks_d = ticks_q + 1'b1;
	if(ticks_d > pulse_period)
		begin
			ticks_d = 0;
		end
	pwm_d = (ticks_d < pulse_width)?1'b1:1'b0;
end

always@(posedge clk)//change
begin
	if(rst)
		begin
			ticks_q <= 8'b0;
		end
	else
		begin
			ticks_q <= ticks_d;
		end
	pwm_q <= pwm_d;
end
assign pwm_out = pwm_q;

endmodule
	
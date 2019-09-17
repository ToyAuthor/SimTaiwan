
local  msg = require "toy.logger"
local  bug = require "toy.debug"

local function create_window()
	local  config =
	{
		title = "Hello World",
		width = 800,
		height = 600,
	}

	return require("toy.graph").create_window(config)
end

local function main()
	msg.print("Hello World")

	local  window = create_window()

	-- 這個遊戲主迴圈感覺還有很多改進空間
	while window:handle_event() do     -- Mouse event, keyboard event, system event, etc.
		window:display()
	end
end

-- Just a try-catch block
if bug.catch(main) then
	bug.oops()
end

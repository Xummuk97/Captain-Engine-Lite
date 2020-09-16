function onEngineSetup()
	window:create("Captain Engine 1.0", 800, 600)

	core:loadTexture("test", "test1.png")
	base = level:addLayer("base")
	level:spawnObject(base, "Player")
end

function onObjectCreate(obj)
	if obj:getType() == "Player" then
		obj:addComponent("componentDrawable")

		componentDrawable = obj:getComponent("componentDrawable")
		componentDrawable:setTexture("test")
		componentDrawable:setTextureRect(0, 0, 32, 32)

		obj:addComponent("componentPhysix")
	end
end

function onGUI()
end
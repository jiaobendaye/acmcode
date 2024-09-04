
function all_code() 
    local res = {}
    for _, x in pairs(os.files("*.cpp")) do 
        local item = {}
        local s = path.filename(x)
        table.insert(item, s:sub(1, #s-4))
        table.insert(item, path.relative(x, "."))
        table.insert(res, item)
    end
    return res
end

for _, code in ipairs(all_code()) do
target(code[1])
    set_default(true)
    set_group("huawei")
    set_kind("binary")
    add_files(code[2])
end

# Create temporary directory
mkdir temp

# Separate target files
cp keymap.yaml temp/keymap.yaml
cp keymap.yaml temp/keymap-noseperatecombos.yaml
cp keymap.yaml temp/keymap-onlyseperatecombos.yaml

yq -i 'del(.combos[] | select(.draw_separate == true))' temp/keymap-noseperatecombos.yaml
yq -i 'del(.combos[] | select(.draw_separate != true))' temp/keymap-onlyseperatecombos.yaml

cp temp/keymap-onlyseperatecombos.yaml temp/keymap-onlyshortcutcombos.yaml
cp temp/keymap-onlyseperatecombos.yaml temp/keymap-onlynavcombos.yaml

yq -i 'del(.combos[] | select(.layers | contains(["shortcuts"]) | not))' temp/keymap-onlyshortcutcombos.yaml
yq -i 'del(.combos[] | select(.layers | contains(["nav"]) | not))' temp/keymap-onlynavcombos.yaml

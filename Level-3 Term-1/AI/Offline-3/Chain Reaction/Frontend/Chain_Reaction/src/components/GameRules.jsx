import { Box, Dialog, DialogTitle, DialogContent, DialogActions, Button, Typography, List, ListItem, ListItemIcon, ListItemText } from '@mui/material';
import FiberManualRecordIcon from '@mui/icons-material/FiberManualRecord';

const GameRules = ({ open, onClose }) => {
  return (
    <Dialog
      open={open}
      onClose={onClose}
      maxWidth="sm"
      fullWidth
      PaperProps={{
        sx: {
          borderRadius: 3,
          boxShadow: '0px 10px 40px rgba(0, 0, 0, 0.15)',
        }
      }}
    >
      <DialogTitle sx={{ pb: 1 }}>
        <Typography variant="h5" fontWeight="bold">
          Chain Reaction Game Rules
        </Typography>
      </DialogTitle>
      
      <DialogContent>
        <Box sx={{ mb: 3 }}>
          <Typography variant="subtitle1" fontWeight="bold" gutterBottom>
            Game Objective:
          </Typography>
          <Typography variant="body1" paragraph>
            The objective of Chain Reaction is to eliminate your opponent's orbs and
            take control of the entire board.
          </Typography>
        </Box>
        
        <Box sx={{ mb: 3 }}>
          <Typography variant="subtitle1" fontWeight="bold" gutterBottom>
            Gameplay:
          </Typography>
          <List dense disablePadding>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="Players take turns placing orbs on the board." />
            </ListItem>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="Red player goes first, followed by Blue player." />
            </ListItem>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="A player can only place orbs in empty cells or cells already containing their own orbs." />
            </ListItem>
          </List>
        </Box>
        
        <Box sx={{ mb: 3 }}>
          <Typography variant="subtitle1" fontWeight="bold" gutterBottom>
            Critical Mass:
          </Typography>
          <List dense disablePadding>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="Each cell has a critical mass which depends on its position:" />
            </ListItem>
            <ListItem sx={{ pl: 4 }}>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 8 }} />
              </ListItemIcon>
              <ListItemText primary="Corner cells (4 cells): Critical mass = 2" />
            </ListItem>
            <ListItem sx={{ pl: 4 }}>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 8 }} />
              </ListItemIcon>
              <ListItemText primary="Edge cells (not corners): Critical mass = 3" />
            </ListItem>
            <ListItem sx={{ pl: 4 }}>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 8 }} />
              </ListItemIcon>
              <ListItemText primary="Middle cells: Critical mass = 4" />
            </ListItem>
          </List>
        </Box>
        
        <Box>
          <Typography variant="subtitle1" fontWeight="bold" gutterBottom>
            Explosions:
          </Typography>
          <List dense disablePadding>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="When a cell reaches its critical mass, it explodes." />
            </ListItem>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="When a cell explodes, one orb moves to each adjacent cell (not diagonals)." />
            </ListItem>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="All adjacent cells become the color of the exploding cell, even if they were the opponent's orbs." />
            </ListItem>
            <ListItem>
              <ListItemIcon sx={{ minWidth: 32 }}>
                <FiberManualRecordIcon sx={{ fontSize: 12 }} />
              </ListItemIcon>
              <ListItemText primary="Chain reactions occur when an explosion causes another cell to reach its critical mass." />
            </ListItem>
          </List>
        </Box>
      </DialogContent>
      
      <DialogActions sx={{ p: 3, pt: 1 }}>
        <Button onClick={onClose} variant="contained" color="primary">
          Got it!
        </Button>
      </DialogActions>
    </Dialog>
  );
};

export default GameRules; 
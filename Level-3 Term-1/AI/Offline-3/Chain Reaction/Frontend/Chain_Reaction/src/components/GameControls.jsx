import { Box, Button, Typography, useTheme } from '@mui/material';
import { motion } from 'framer-motion';
import RestartAltIcon from '@mui/icons-material/RestartAlt';
import InfoOutlinedIcon from '@mui/icons-material/InfoOutlined';
import VideogameAssetIcon from '@mui/icons-material/VideogameAsset';

const GameControls = ({ onNewGame, onRulesOpen, gameStatus, winner, currentPlayer }) => {
  const theme = useTheme();
  
  console.log('GameControls received currentPlayer:', currentPlayer);
  
  const getStatusColor = () => {
    if (winner === 'R') return '#f44336';
    if (winner === 'B') return '#2196f3';
    if (currentPlayer === 'R') return '#f44336';
    if (currentPlayer === 'B') return '#2196f3';
    return theme.palette.text.primary;
  };
  
  const getStatusText = () => {
    console.log('getStatusText currentPlayer:', currentPlayer);
    if (winner === 'R') return 'Red Player Wins!';
    if (winner === 'B') return 'Blue Player Wins!';
    if (gameStatus === 'active') {
      return `${currentPlayer === 'R' ? 'Red' : 'Blue'}'s Turn`;
    }
    return 'Game Ready';
  };
  
  return (
    <Box 
      sx={{ 
        width: '100%',
        maxWidth: 480,
        mx: 'auto',
        p: 2,
        display: 'flex',
        flexDirection: 'column',
        gap: 2,
      }}
    >
      <Box 
        sx={{
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
        }}
      >
        <Typography variant="h5" component="h1" fontWeight="bold">
          Chain Reaction
        </Typography>
        
        <Box sx={{ display: 'flex', gap: 1 }}>
          <Button 
            variant="outlined" 
            color="primary" 
            startIcon={<InfoOutlinedIcon />}
            size="small"
            onClick={onRulesOpen}
          >
            Rules
          </Button>
          
          <Button 
            variant="contained" 
            color="primary"
            startIcon={<RestartAltIcon />}
            onClick={onNewGame}
            component={motion.button}
            whileHover={{ scale: 1.05 }}
            whileTap={{ scale: 0.95 }}
          >
            New Game
          </Button>
        </Box>
      </Box>
      
      <Box 
        component={motion.div}
        initial={{ opacity: 0, y: 20 }}
        animate={{ opacity: 1, y: 0 }}
        transition={{ duration: 0.5 }}
        sx={{
          backgroundColor: theme.palette.background.paper,
          borderRadius: 2,
          p: 2,
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'center',
          gap: 1,
          boxShadow: '0px 4px 12px rgba(0, 0, 0, 0.05)',
          border: '1px solid',
          borderColor: theme.palette.divider,
        }}
      >
        <VideogameAssetIcon 
          sx={{ 
            color: getStatusColor(),
            fontSize: 24
          }} 
        />
        <Typography
          variant="h6"
          sx={{
            color: getStatusColor(),
            fontWeight: 'bold'
          }}
        >
          {getStatusText()}
        </Typography>
      </Box>
    </Box>
  );
};

export default GameControls; 
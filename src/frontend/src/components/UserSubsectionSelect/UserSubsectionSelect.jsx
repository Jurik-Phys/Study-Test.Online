import style from './UserSubsectionSelect.module.css'
import { useNavigate } from "react-router-dom"

const UserSubsectionSelectPage = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Education
        </div>
        <div className={style.imageBox}>
          <div>
            <img src="phys.png" alt="Physics.png" onClick={ ()=>navigate('/user-challenge-select')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-challenge-select')}>Physics (a)</div>
          </div>
          <div>
            <img src="math.png" alt="Mathematics.png" onClick={ ()=>navigate('/user-challenge-select')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-challenge-select')}>Mathematics (b)</div>
          </div>
          <div>
            <img src="safety.png" alt="Life safety.png" onClick={ ()=>navigate('/user-challenge-select')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-challenge-select')}>Life safety (z)</div>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate('/')} >Back to Home</button>
        </div>
      </div>
  );
}

export default UserSubsectionSelectPage;
